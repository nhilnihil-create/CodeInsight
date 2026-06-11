#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main() {
    int n,m;cin>>n>>m;
    ll a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    
    vector<ll>vec;
    pair<ll,int>p[m];
    
    rep(i,m){
        int b;
        ll c;
        cin>>b>>c;
        p[i].first = c;
        p[i].second= b;
    }
    sort(p,p+m,greater<pair<ll,int>>());

    rep(i,m){
        int cc = p[i].second;
        rep(j,cc)vec.push_back(p[i].first);
        if(vec.size()>=n)break;
    }
    
    sort(vec.begin(),vec.end(),greater<ll>());
    
    int tmp = vec.size();
    rep(i,min(n,tmp)){
        if(a[i]<vec[i])a[i]=vec[i];
    }
    
    ll ans=0;
    rep(i,n)ans+=a[i];
    cout<<ans<<endl;

	return 0;
}