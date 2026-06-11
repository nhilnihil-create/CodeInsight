#include <bits/stdc++.h>
using namespace std;

#define ALL(obj) (obj).begin(), (obj).end()
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,b) for(int i=a; i<=b; i++)
#define drep2(i,a,b) for(int i=a; i>=b; i--)
using ll = long long;
#define pb push_back

class TWO {
  public:
    ll pos;
    ll value;
    TWO ( ll pos, ll value) : pos(pos), value(value) {} 
};


ll get_max(vector<ll>x, vector<ll>v, int N, ll C) 
{
  ll nowp = 0;
  vector<ll> cum_cl(N);
  vector<ll> max_cl(N);

  cum_cl[0] = 0;

  rep(i,  N) {
    if (i == 0 )
      cum_cl[i] = v[i] - ( x[i] - nowp ) ;
    else 
      cum_cl[i] = cum_cl[i-1] + v[i] - (x[i] - nowp);
    nowp = x[i];
  }
  ll mmax = LLONG_MIN;
  rep(i, N ) {
    if (cum_cl[i] > mmax) {
      mmax = cum_cl[i];
      max_cl[i] = max(cum_cl[i], mmax);
    } else {
      max_cl[i] = mmax;
    }
  }
  ll limit = -1;
  nowp = C;
  ll nowv = 0;
  ll maxvans = 0;

  // counter clock -> then clock
  drep2(i, N, 0) {
    if (i == N) {
      limit = i - 1;
      maxvans = max(maxvans, max_cl[limit]);
      continue;
    }
    nowv += v[i] - (nowp - x[i]);
    limit = i-1;
    nowp = x[i];
    if (limit == -1) 
      maxvans = max(maxvans, nowv);
    else
      maxvans = max(maxvans, max(nowv, nowv-(C-x[i])+max_cl[limit]));

  //  cout << "nowv: " << nowv << endl;
  //  cout << "limit: " << limit << endl;
  //  cout << "nowp: " << nowp << endl;
  //  cout << "maxvans: " << maxvans << endl;
  //
  //  cout << "--------"  << endl << endl;
  }
  return maxvans;

}

int main()
{
  int N;
  ll C;
  cin >> N >> C;
  vector<ll> x(N), v(N);
  vector<TWO> tt;
  rep(i, N ) {
    cin >> x[i] >> v[i];
    tt.pb(TWO(x[i], v[i]));
  }
  sort(ALL(tt), [](const TWO& l, const TWO& r) { return l.pos < r.pos; });
  rep(i, N) {
    TWO temp_two = tt[i];
    x[i] = temp_two.pos;
    v[i] = temp_two.value;
  }
  //rep(i, N) {
  //  cout << "x[" << i << "]: " << x[i] << ", v[" << i << "]: " << v[i] << endl;
  //}


  /////////////////////
  //    get_max      //
  /////////////////////

  // rep(i, N) {
  //   cout << "cum : " << cum_cl[i] << endl;
  //   cout << "mmax_cum : " << max_cl[i] << endl;
  // }

  ll max_vans = get_max(x,v,N, C);
  //cout << "max_vans: " << max_vans << endl;


  sort(ALL(tt), [](const TWO& l, const TWO& r) { return l.pos > r.pos; });
  rep(i, N) {
    TWO temp_two = tt[i];
    x[i] = C- temp_two.pos;
    v[i] = temp_two.value;
    //cout << "x[" << i << "]: " << x[i] << endl;
    //cout << "v[" << i << "]: " << v[i] << endl;
  }

  max_vans = max(max_vans, get_max(x,v,N,C));
  cout << max_vans << endl;

  // max vans
  // COUNTERCLOCK -> CLOCK 
  // の値は手に入った


}