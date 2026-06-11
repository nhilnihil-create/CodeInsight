/**
*    author:  yuya1234
*    created: 10.07.2020 16:47:23
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

  int x[n],xx[n];
  REP(i,n){
    cin>>x[i];
    xx[i]=x[i];
  }

  sort(xx,xx+n);
  int c1,c2;
  c1=xx[(n/2)-1];
  c2=xx[n/2];

  REP(i,n)
  {
    if(c1>=x[i])cout<<c2<<endl;
    else cout<<c1<<endl;
  }

  return 0;
}