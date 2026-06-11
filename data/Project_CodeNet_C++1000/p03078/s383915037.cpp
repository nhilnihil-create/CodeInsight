#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<deque>
#include<set>
using namespace std;

using ll = long long;
const int INF = 1001001001;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(void)
{
  ll x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x);
  vector<ll> b(y);
  vector<ll> c(z);
  rep(i,x) cin >> a[i];
  rep(i,y) cin >> b[i];
  rep(i,z) cin >> c[i];

  sort(a.begin(), a.end(), greater<ll>());
  sort(b.begin(), b.end(), greater<ll>());
  sort(c.begin(), c.end(), greater<ll>());

  vector<ll> ab;
  rep(i,x) rep(j,y) {
    ab.push_back(a[i]+b[j]);
  }
  sort(ab.begin(), ab.end(), greater<ll>());

  vector<ll> abc;
  rep(i, min((ll)3000, x*y)) rep(j, z) {
    abc.push_back(ab[i]+c[j]);
  }
  sort(abc.begin(), abc.end(), greater<ll>());
  rep(i,k) {
    cout << abc[i] << endl;
  }
}
