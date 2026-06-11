/**
*    author:  yuya1234
*    created: 09.07.2020 09:28:00
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

  int r,g,b,n;
  cin>>r>>g>>b>>n;

  ll cnt=0;
  REP(i,n/r+1)REP(j,n/g+1)
  {
    if((n-i*r-j*g)%b==0 && n-i*r-j*g>=0)
    {
      cnt++;
    }
  }

  cout<<cnt<<endl;

  return 0;
}