//https://drken1215.hatenablog.com/entry/2018/09/08/195000
//https://ikatakos.com/pot/programming_algorithm/contest_history/atcoder/2018/0407_arc094
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int q;
ll solve(ll a,ll b){
   ll ans;
   ll s=ll(sqrt(a*b));
   ans=2*s-1;
   if(s*(s+1)>=a*b)ans--;
   if(s*s==a*b&&a!=b)ans--;

   return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>q;
    rep(i,q)
    {
        ll a,b;
        cin>>a>>b;
    cout<<solve(a,b)<<endl;
    }
    return 0;
}
 