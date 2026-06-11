/**
*    author:  yuya1234
*    created: 09.07.2020 11:11:54
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

  int n,k;
  cin>>n>>k;

  double ans=0;
  int tmp=0;
  REPD(i,n)
  {
    while(k>(i+1)*pow(2,tmp))
    {
      tmp++;
    }
    if(tmp==0)ans+=(1.0/n);    
    else ans+=(1.0/n)*pow(0.5,tmp);    
  }

  printf("%.12lf\n",ans);

  return 0;
}