#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define debug(x) cerr<<#x<<" "<<x<<'\n';
bool cmp(pair<ll,ll> a, pair<ll,ll> b) { return a.second > b.second; }
ll mod = 1e9+7;

signed main() {
    ll n; cin>>n;
    vector<pair<ll,ll>>a(n),b(n);
    rep(i,n)cin>>a[i].first>>a[i].second;
    rep(i,n)cin>>b[i].first>>b[i].second;
    sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end());
    
    rep(i, n) {
        int bx = b[i].first, by = b[i].second;
        rep(i,a.size()){
           int ax=a[i].first,ay=a[i].second;
           if(ax<bx&&ay<by){
               a.erase(a.begin()+i);
               break;
           }
        }
    }
    cout << n-a.size() << endl;
}