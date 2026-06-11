/**
*    author:  yuya1234
*    created: 14.07.2020 09:51:38
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

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  //std::cout << std::fixed << std::setprecision(15);

  ll n,m;
  string s,t;
  cin>>n>>m>>s>>t;

  ll _gcd=gcd(n,m);
  ll lcm=_gcd*n/_gcd*m/_gcd;
  ll ans=-1;
  ll ss[n];
  ll tt[m];
  REP(i,n){
    ss[i]=1+(lcm/n)*i;
  }
  REP(i,m){
    tt[i]=1+(lcm/m)*i;
  }
  int i=0;
  int j=0;
  for(;;)
  {
    if(ss[i]==tt[j])
    {
      if(s[i]!=t[j])break;
      i++;
      j++;
    }
    else
    {
      if(ss[i]>tt[j])j++;
      else i++;
    }

    if(i==n || j==m)
    {
      ans=lcm;
      break;
    }
  }

  cout<<ans<<endl;

  return 0;
}