//http://baitop.hatenadiary.jp/entry/2018/07/09/193455
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int n;
vector<ll>a,b,c,d;
ll solve(){
   ll ans=0;
   c.resize(n);
   d.resize(n);

   rep(i,29){
       ll cnt=0;
       ll t=1<<i;
       rep(j,n){
           c[j]=a[j]%(2*t);
           d[j]=b[j]%(2*t);
       }
       sort(d.begin(),d.end());
       rep(ci,n){
           cnt+=lower_bound(d.begin(),d.end(),2*t-c[ci])-lower_bound(d.begin(),d.end(),t-c[ci]);
           cnt+=lower_bound(d.begin(),d.end(),4*t-c[ci])-lower_bound(d.begin(),d.end(),3*t-c[ci]);
       }
       ans|=(cnt&1)<<i;
   }

   return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    a.resize(n);
    b.resize(n);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    cout<<solve()<<endl;
    return 0;
}