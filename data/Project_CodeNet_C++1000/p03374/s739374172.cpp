#include <bits/stdc++.h>
using namespace std;
#define null NULL
#define mp make_pair
#define pb(a) push_back(a)
#define sz(a) ((int)(a).size())
#define all(a) a.begin() , a.end()
#define fi first
#define se second
#define relaxMin(a , b) (a) = min((a),(b))
#define relaxMax(a , b) (a) = max((a),(b))
#define SQR(a) ((a)*(a))
#define PI 3.14159265358979323846
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

typedef pair<ll, ll> pll;

ll n, c;
vector<pll> in;

vector<ll> cw, ccw;
vector<ll> max_cw, max_ccw;

int main(){
  scanf("%lld%lld", &n, &c);
  in.resize(n);
  for(int i = 0;i < n;++i)
    scanf("%lld%lld", &in[i].fi, &in[i].se);

  sort(all(in));

  cw.resize(n), ccw.resize(n);
  max_cw.resize(n), max_ccw.resize(n);

  ll sum = 0;
  for(int i = 0;i < n;++i){
    sum += in[i].se;
    ll dist = in[i].fi;
    cw[i] = sum - dist;
  }
  max_cw[0] = max(0LL, cw[0]);
  for(int i = 1;i < n;++i)
    max_cw[i] = max(cw[i], max_cw[i - 1]);

  sum = 0;
  for(int i = n - 1;i >= 0;--i){
    sum += in[i].se;
    ll dist = c - in[i].fi;
    ccw[i] = sum - dist;
  }
  max_ccw[n - 1] = max(0LL, ccw[n - 1]);
  for(int i = n - 2;i >= 0;--i)
    max_ccw[i] = max(max_ccw[i + 1], ccw[i]);

  ll best = max(max_cw[n - 1], max_ccw[0]);

  for(int i = 0;i + 1 < n;++i){
    ll val = max_ccw[i + 1] + cw[i] - in[i].fi;
    relaxMax(best, val);
  }

  for(int i = n - 1;i > 0;--i){
    ll val = max_cw[i - 1] + ccw[i] - (c - in[i].fi);
    relaxMax(best, val);
  }

  printf("%lld\n", best);

  return 0;
}

