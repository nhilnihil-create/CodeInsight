/**
*    author:  yuya1234
*    created: 08.07.2020 16:45:50
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

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string s,ss;
  cin>>s;
  ss=s;

  string m="keyence";
  int cnt=0;

  REP(i,SZ(m))
  {
    if(m[i]==s[i])cnt++;
    else break;
  }

  if(cnt==0)
  {
    REPD(i,SZ(m))
    {
      if(m[i]==s[SZ(s)-SZ(m)+i])cnt++;
      else break;
    }
  }
  else if(cnt!=7)
  {
    REPD(i,SZ(m))
    {
      if(m[i]==s[SZ(s)-SZ(m)+i])cnt++;
      else break;
    }
  }

  if(cnt>=7)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

  return 0;
}