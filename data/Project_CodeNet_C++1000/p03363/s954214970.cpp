//url:
//problem name:

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long,long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

const ll MAX = 1LL<<60;

int main() {
    int N; cin >> N;
    vector<ll> a(N),s(N+1);
    REP(i,N) cin >> a[i];
    REP(i,N) s[i+1] = s[i] + a[i];
    map<ll,ll> res;
    REP(i,N+1) 
        if(res.count(s[i])) res[s[i]]++;
        else res[s[i]] = 1;
    ll ans = 0;
    for(auto x:res) {
        //cout << x.first << " " << x.second << endl;
        ans += x.second * (x.second - 1) / 2;
    }
    cout << ans << endl;
}