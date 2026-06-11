#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 998244353;
const double PI = 3.1415926535897;
typedef tuple<int,int,int> TP;

template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}
 
ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}
 
ll RS(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P < 0) {
        return 0;
    }
    if(P%2==0){
        ll t = RS(N, P/2, M);
        return t*t % M;
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<ll> Mcount(N + 1);//Mcount.at(i) = i番目(1-indexed)までのMの個数
    vector<ll> Ccount(N + 1);//Ccount.at(i) = i番目(1-indexed)までのCの個数
    vector<ll> CMcount(N + 1);//CMcount.at(i) = i番目以降のCに対するMcountの合計
    for(int i = 0;i < N;i++) {
        if(S.at(i) == 'M') {
            Mcount.at(i + 1) = Mcount.at(i) + 1;
        }
        else {
            Mcount.at(i + 1) = Mcount.at(i);
        }
    }
    for(int i = 0;i < N;i++) {
        if(S.at(i) == 'C') {
            Ccount.at(i + 1) = Ccount.at(i) + 1;
            CMcount.at(i + 1) = CMcount.at(i) + Mcount.at(i);
        }
        else {
            Ccount.at(i + 1) = Ccount.at(i);
            CMcount.at(i + 1) = CMcount.at(i);
        }
    }
    int Q;
    cin >> Q;
    for(int i = 0;i < Q;i++) {
        int A;
        cin >> A;
        ll ret = 0;
        for(int j = 0;j < N;j++) {
            if(S.at(j) == 'D' && j + A <= N) {
                ret += (CMcount.at(j + A) - CMcount.at(j)) - Mcount.at(j) * (Ccount.at(j + A) - Ccount.at(j));
            }
            else if(S.at(j) == 'D') {
                ret += (CMcount.at(N) - CMcount.at(j)) - Mcount.at(j) * (Ccount.at(N) - Ccount.at(j));
            }
        }
        cout << ret << endl;
    }
}