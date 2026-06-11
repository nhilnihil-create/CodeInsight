/**
*    author:  yuya1234
*    created: 10.07.2020 13:12:10
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n,m;
  cin>>n>>m;

  int x[m];
  REP(i,m)cin>>x[i];

  sort(x,x+m);

  int xx[m-1];
  REP(i,m-1)xx[i]=x[i+1]-x[i];

  sort(xx,xx+m-1,greater<int>());

  ll ans=0;
  if(n<m)
  {
    FOR(i,n-1,m-2)
    {
      ans+=xx[i];
    }
  }
  
  cout<<ans<<endl;

  return 0;
}