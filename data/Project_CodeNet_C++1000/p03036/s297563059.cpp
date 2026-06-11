/*

 Remember, Hope is a good thing... May be the best of things... and No Good thing ever Dies !!!

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007
const ll inf=(1LL<<60)-1;
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
void solve()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   ll r,D,x2000,x1,t;
   cin>>r>>D>>x2000;
   t=x2000;
   for(ll i=0;i<=9;i++)
   {
       x1=r*t-D;
       cout<<x1<<endl;
       t=x1;
   }

}
int main()
{
    IOS;
    //ll t;
    //cin>>t;
    //while(t--)
    solve();
    return 0;
}
