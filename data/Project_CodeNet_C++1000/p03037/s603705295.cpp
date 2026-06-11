#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> l(m);
    vector<int> r(m);
    rep(i,m) cin>>l[i]>>r[i];

    sort(l.begin(),l.end(),greater<int>());
    sort(r.begin(),r.end());

    int ans=r[0]-l[0]+1;
    if(ans<0) ans=0;
    cout<<ans<<"\n";
    return 0;
}