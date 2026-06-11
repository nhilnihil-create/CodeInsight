#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    vector<tuple<int,int,int>>t(n);
    rep(i,n){
        cin>>a[i]>>b[i];
        t[i]=make_tuple(a[i]+b[i],a[i],b[i]);
    }
    ll ans=0;
    sort(t.rbegin(),t.rend());
    rep(i,n){
        if(i%2==0)ans+=get<1>(t[i]);
        else ans-=get<2>(t[i]);
    }
    cout<<ans<<endl;
    return 0;
}