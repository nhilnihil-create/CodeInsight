#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
#define vl vector<ll>
bool cmp(pair<ll,ll> a, pair<ll,ll> b) { return a.second > b.second; }

signed main() {
    ll n; cin>>n;
    vector<pair<ll,ll>>r(n),b(n);
    rep(i,n)cin>>r[i].first>>r[i].second;
    rep(i,n)cin>>b[i].first>>b[i].second;
    sort(r.begin(),r.end(),cmp);
    sort(b.begin(),b.end());

    rep(i,n)rep(j,r.size()){
           if(r[j].first<b[i].first&&r[j].second<b[i].second){
               r.erase(r.begin()+j);
               break;
           }
    }
    cout << n-r.size() << endl;
}