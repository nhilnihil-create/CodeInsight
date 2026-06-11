/**
*    author:  yuya1234
*    created: 09.07.2020 17:04:17
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define ALL(v) (s).begin(), (s).end()
#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

ll gcd(ll a, ll b)
{
   if (a%b == 0)return(b);
   else return(gcd(b, a%b));
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n,x;
  cin>>n>>x;

  vector<int> v;
  int tmp;
  REP(i,n)
  {
    cin>>tmp;
    v.emplace_back(tmp);
  }
  v.emplace_back(x);

  SORTD(v);
  ll ans=INT_MAX,diff=0,pre;
  pre=v[0]-v[1];
  REP(i,n)
  {
    diff=gcd(pre,v[i]-v[i+1]);
    if(ans>diff)
    {
      ans=diff;
      pre=diff;
    }
  }

  cout<<ans<<endl;



  return 0;
}