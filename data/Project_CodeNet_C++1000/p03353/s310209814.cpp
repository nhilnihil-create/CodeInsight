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
   
    string s;
    int k;
    cin >> s >> k;
    vector<string> x;
    vector<string> y;
    REP(i, s.size()){
        FOR(j, 0, 5){
            if(i + j < s.size())
            x.push_back(s.substr(i, j+1));
        }
    }
    sort(x.begin(),x.end());
    // REP(i, x.size()){
    //     cout << x[i] << endl;
    // }

    REP(i, x.size()){
        if(i == 0) y.push_back(x[i]);
        else {
            if(x[i] != y[y.size()-1]){
                y.push_back(x[i]);
            }
        }
    }
    cout << y[k-1] << endl;
}

