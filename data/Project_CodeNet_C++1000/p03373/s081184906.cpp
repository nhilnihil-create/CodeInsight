#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int a,b,c,x,y;
ll solve(){
   ll ans=0;

    if(a+b<=2*c)ans=x*a+y*b;
    else{
      ll m=min(x,y);
      ans=2*c*m+(x-m)*a+(y-m)*b;
      chmin(ans,ll(2*c*max(x,y)));
    }
   return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b>>c>>x>>y;
    cout<<solve()<<endl;
    return 0;
}