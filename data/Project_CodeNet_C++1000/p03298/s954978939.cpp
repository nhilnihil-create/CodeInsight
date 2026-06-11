#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000010;
constexpr ll INF= 1000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

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
    cin >> N;
    string S;
    cin >> S;
    map<pair<string,string>,ll> A;
    map<pair<string,string>,ll> B;
    for(int bit = 0;bit < (1 << N);bit++) {
        vector<bool> cnt(N);
        for(int i = 0;i < N;i++) {
            if(bit & (1 << i)) {
                cnt.at(i) = true;
            }
        }
        string cnt1 = "";
        string cnt2 = "";
        string cnt3 = "";
        string cnt4 = "";
        for(int i = 0;i < N;i++) {
            if(cnt.at(i) == true) {
                cnt1.push_back(S.at(i));
                cnt3.push_back(S.at(2 * N - 1 - i));
            }
            else {
                cnt2.push_back(S.at(i));
                cnt4.push_back(S.at(2 * N - 1 - i));
            }
        }
        A[make_pair(cnt1,cnt2)]++;
        B[make_pair(cnt3,cnt4)]++;
    }
    ll ret = 0;
    for(auto x:A) {
        if(B.count(make_pair(x.first.second,x.first.first))) {
            ret += x.second * B[make_pair(x.first.second,x.first.first)];
        }
    }
    cout << ret << endl;
}