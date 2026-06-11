/**
*    author:  yuya1234
*    created: 10.07.2020 11:39:54
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

  ll k,a,b;
  cin>>k>>a>>b;

  ll sum=1,kt;
  kt=k;
  if(b-a>2)
  {
    kt-=a-1;
    sum+=a-1;
    if(kt%2==0)sum+=(kt/2)*(b-a);
    else
    {
      sum+=(kt/2)*(b-a);
      sum++;
    }
  }
  else
  {
    sum=1+k;
  }

  cout<<sum<<endl;

  return 0;
}