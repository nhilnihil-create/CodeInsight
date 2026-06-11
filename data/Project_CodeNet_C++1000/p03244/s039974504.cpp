/**
*    author:  yuya1234
*    created: 03.09.2020 13:17:54
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
long double eps = 1.0E-14;

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
template<class T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a,T b){return gcd(a,b)*(a/gcd(a,b))*(b/gcd(a,b));}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(15);

  int n;
  cin>>n;

  int *a=new int[100001];
  int *b=new int[100001];

  REP(i,100001)
  {
    a[i]=b[i]=0;
  }

  int tmp;
  REP(i,n)
  {
    cin>>tmp;
    if(i%2==0)a[tmp]++;
    else b[tmp]++;
  }

  int max11,max12,max21,max22;
  max11=max12=max21=max22=0;

  int idx11,idx12,idx21,idx22;
  idx11=idx12=idx21=idx22=0;

  FOR(i,1,100000)
  {
    if(chmax(max11,a[i])){max21=a[idx11];idx21=idx11;idx11=i;}
    else if(chmax(max21,a[i]))idx21=i;
  }

  FOR(i,1,100000)
  {
    if(chmax(max12,b[i])){max22=a[idx12];idx22=idx12;idx12=i;}
    else if(chmax(max22,b[i]))idx22=i;
  }

  int ans=0;
  if(idx11!=idx12)ans=n-max11-max12;
  else ans=n-max(max11+max22,max21+max12);

  cout<<ans<<endl;



  return 0;
}