#include<bits/stdc++.h>
#include<bitset>
#include<random>
#include<time.h>

using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 5e5 + 10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code
int morex[N];
int lessx[N];
int morey[N];
int lessy[N];

vector<pair<ll, ll>> vpx;

int main()
{
  int n , k;
  cin>>n>>k;
  rep(i, 0, n)
  {
    ll x, y;
    cin>>x>>y;
    vpx.pb({x, y});
  }
  sort(vpx.begin(), vpx.end());
  ll ans = LONG_MAX;
  rep(i, 0, n)
    rep(j, i, n)
    {

      ll x1, x2, y1, y2;
      x1 = vpx[i].f;
      x2 = vpx[j].f;
      ll co = 0;
      vector<pair<ll, ll>> vpy;
      repn(kk, i, j)
      {
        vpy.pb({vpx[kk].s, vpx[kk].f});
      }
      sort(vpy.begin(), vpy.end());
      if(vpy.size() >= k)
      {
        ll aa = x2 - x1;
        for(int kk=0;(kk+k)<=vpy.size(); kk++)
        {
          ll y1 = vpy[kk].f;
          ll y2 = vpy[kk+k-1].f;
          ll area = aa * (y2- y1);
          if(area < ans) ans = area;
        }
      }

    }
  cout<<ans<<endl;
}
