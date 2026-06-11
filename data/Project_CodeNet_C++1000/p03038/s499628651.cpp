//url:
//problem name: 

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

int main() {
    int N,M;
    cin >> N >> M;
    map<ll,ll> mp;
    REP(i,N) {
        ll a;
        cin >> a;
        if(mp.count(a)) mp[a]++;
        else mp[a] = 1;
    }
    REP(i,M) {
        ll b,c;
        cin >> b >> c;
        if(mp.count(c)) mp[c] += b;
        else mp[c] = b;
    }
    vector<pair<ll,ll>> res;
    ll ans = 0;
    for(auto x : mp) res.push_back(x);
    sort(res.begin(),res.end(),greater<pair<ll,ll>>());
    for(auto x : res) {
        ll c = x.first;
        ll b = x.second;
        if(b < N) ans += c*b;
        else {
            ans += c*N;
            break;
        }
        N -= b;
    }
    cout << ans << endl;
}
