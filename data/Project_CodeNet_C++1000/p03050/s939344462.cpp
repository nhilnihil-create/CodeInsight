#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

vecl dividers(ll N) {
    vecl res;
    for(ll i = 1; i * i <= N; i++) {
        if(N%i == 0) {
            res.push_back(i);
            if(i != N/i) res.push_back(N/i);
        }
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    vecl res = dividers(N);
    ll ans = 0;
    for(ll p : res) {
        if(1 <= p && p <= N-1) {
            ll m = N/p-1;
            if(N/m == N%m) ans += m;
        }
    }
    cout << ans << endl;
}