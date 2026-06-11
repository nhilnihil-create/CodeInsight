#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD (int)1e9+7
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>b;--i)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()

ll powM(ll a,ll b,ll m )
{ 
  a%=m;
  ll ans=1;
  while(b>0)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }

return ans;
}



int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

int n;
cin>>n;

stringstream ss;
ss<<n;
string s=ss.str();

for(char x:s)
  {
    if(x=='9')x='1';
    else if(x=='1')x='9';
    cout<<x;
  }

  //cout<<s<<"\n";

return 0;

}
