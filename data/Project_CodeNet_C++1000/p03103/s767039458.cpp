#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n,m;cin >>n>>m;
    vector<P>p(n);
    for (int i = 0; i < n; ++i) {
        ll a,b;cin >>a>>b;
        p[i]=make_pair(a,b);
    }
    sort(all(p));
    ll ans=0;
    for (int i = 0; i < n; ++i) {
//        cout <<ans <<endl;
        ans+=min(m,p[i].second)*p[i].first;
        m-=p[i].second;
        if(m<=0)break;
    }
    cout <<ans <<endl;
    return 0;
}

