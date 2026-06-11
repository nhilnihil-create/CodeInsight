#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
 
#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2);

int main()
{
  ll N;cin>>N;
  ll a,b,c,d,e;cin>>a>>b>>c>>d>>e;
  
  ll mn = min({a,b,c,d,e});
  //水流はmn/分
  //何回で全員ゴールに行けるか？
  ll ans=0;
  if (N%mn==0) ans = N/mn+4;
  else ans = N/mn+5;

  cout<<ans<<endl;
}