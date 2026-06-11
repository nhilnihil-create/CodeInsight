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
  ll n;
  cin>>n;
  ll l=n/100;
  ll r=n%100;
  if(1<=l && l<=12)
  {
      if(1<=r && r<=12)
        cout<<"AMBIGUOUS"<<endl;
      else
        cout<<"MMYY"<<endl;
  }
  else
  {
      if(1<=r && r<=12)
        cout<<"YYMM"<<endl;
      else
        cout<<"NA"<<endl;
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
