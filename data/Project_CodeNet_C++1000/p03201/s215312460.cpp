#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;
 
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
    if(P%2==0){
        ll t = RS(N, P/2, M);
        return t*t % M;
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N;
    cin >> N;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    map<ll,ll> ma;
    for(int i = 0;i < N;i++) {
        ma[-vec.at(i)]++;
    }
    ll ret = 0;
    for(int i = 0;i < N && !ma.empty();i++) {
        ll val = -ma.begin()->first;
        ma[-val]--;
        if(ma[-val] == 0) {
            ma.erase(-val);
        }
        ll A = 1;
        while(A <= val) {
            A *= 2;
        }
        A -= val;
        if(ma.count(-A)) {
            ret++;
            ma[-A]--;
            if(ma[-A] == 0) {
                ma.erase(-A);
            }
        }   
    }
    cout << ret << endl;
}