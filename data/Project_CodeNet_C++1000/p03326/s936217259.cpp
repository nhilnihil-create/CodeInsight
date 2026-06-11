#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 1000
#define rop(i,n) for ( int i = 0; i < n; ++i )

using namespace std;

typedef long long ll;

ll x[MAXN], y[MAXN], z[MAXN];
ll t[MAXN];
int N,M;

ll func ( int fx, int fy, int fz )
{
  ll ans = 0;
  rop(i,N) {
    ll tmp = 0;
    if ( fx == 0 ) tmp += -x[i];
    else tmp += x[i];
    if ( fy == 0 ) tmp += -y[i];
    else tmp += y[i];
    if ( fz == 0 ) tmp += -z[i];
    else tmp += z[i];
    t[i] = tmp;
    //cout << "tmp = " << tmp << endl;
  }

  sort ( t, t+N, greater<ll>());

  rop(i,M) {
    ans += t[i];
  }

  //cout << "ans = " << ans << endl;
  return ans;
}

int main()
{
  ll ans,tmp;
  cin >> N >> M;

  for ( int j = 0; j < N; ++j) {
    //scanf("%ld%ld%ld", &x[j], &y[j], &z[j]);
    cin >> x[j] >> y[j] >> z[j];
  }
  /*
  for ( int i = 0; i < N; ++i ) {
    printf("%ld, %ld, %ld\n", x[i], y[i], z[i]);
  }
  */
  ans = func(1,1,1);
  tmp = func(0,1,1); if ( tmp > ans ) ans = tmp;
  tmp = func(1,0,1); if ( tmp > ans ) ans = tmp;
  tmp = func(1,1,0); if ( tmp > ans ) ans = tmp;
  tmp = func(0,0,1); if ( tmp > ans ) ans = tmp;
  tmp = func(1,0,0); if ( tmp > ans ) ans = tmp;
  tmp = func(0,1,0); if ( tmp > ans ) ans = tmp;
  tmp = func(0,0,0); if ( tmp > ans ) ans = tmp;

  cout << ans << endl;
}
