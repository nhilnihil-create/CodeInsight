/**
*    author:  yuya1234
*    created: 08.07.2020 11:49:06
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

  int n;
  string s;
  cin>>n>>s;

  int a[26],b[26];
  MEMSET(a,0);
  MEMSET(b,0);

  REP(i,n)a[s[i]-'a']++;

  int cnt=0,ans=0;
  REP(i,SZ(s)-1)
  {
    if(a[s[i]-'a']!=0)
    {
      a[s[i]-'a']--;
      b[s[i]-'a']++;
    }

    cnt=0;
    REP(i,26)
    {
      if(a[i]>0 && b[i]>0)cnt++;
    }
    ans=max(ans,cnt);
  }

  cout<<ans<<endl;

  return 0;
}