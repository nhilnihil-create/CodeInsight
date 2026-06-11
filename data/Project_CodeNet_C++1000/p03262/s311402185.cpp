#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n),b(n);
    rep(i,n)cin>>a[i];
    a.push_back(x);
    sort(a.begin(),a.end());
    rep(i,n)b[i]=abs(a[i]-a[i+1]);
    int ans=0;
    rep(i,n)ans=__gcd(ans,b[i]);
    cout<<ans<<endl;
}