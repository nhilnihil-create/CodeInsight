#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#include <map>
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using Graph = vector<vector<int>>;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll modinv(ll a, ll m){
    ll b = m, u = 1, v = 0;
    while(b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if(u < 0) u += m;
    cout << u << endl;
    return u;
}

 
int main() {
   
    int X;
    cin >> X ;
    int ma = -1;
    FOR(i,1, 36){
        int x = i;
        FOR(j, 1, 11){
            x *= i;
            if(x > X){
                break;
            }
            ma = max(ma, x);
        }
    }
    cout << ma << endl;

}

