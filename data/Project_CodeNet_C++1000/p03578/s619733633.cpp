/**
*    author:  yuya1234
*    created: 10.07.2020 11:25:42
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

  int n;
  cin>>n;

  int d[n];
  REP(i,n)cin>>d[i];

  int m;
  cin>>m;

  int t[m];
  REP(i,m)cin>>t[i];

  sort(d,d+n);
  sort(t,t+m);
  int idx=0;
  string ans;

  REP(i,m)
  {
    for(int j=idx;j<n;j++)
    {
      ans="NO";
      if(t[i]==d[j])
      {
        ans="YES";
        idx=j+1;
        break;
      }
    }
    if(ans=="NO")break;
  }

  cout<<ans<<endl;

  return 0;
}