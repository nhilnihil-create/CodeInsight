#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n,m;cin >>n>>m;
    ll x=-1;
    vector<P>p;
    for (int i = 0; i < m; ++i) {
        ll a,b;cin >>a>>b;
        p.push_back({b,a});
    }
    sort(all(p));
    ll ans=0;
    for (int i = 0; i < m; ++i) {
        if(p[i].second<x)continue;
        else {
            x=p[i].first;
            ans++;
        }
    }
    cout <<ans <<endl;
    return 0;
}
