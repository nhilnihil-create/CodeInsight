#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  ll N; cin >> N;
  rep(n, 1, 3501) {
  	rep(h, 1, 3501) {
    	ll wa = N * n * h;
      	ll wb = 4 * n * h - N * h - N * n;
      	if (wa > 0 && wb > 0 && wa % wb == 0) {
        	ll w = wa / wb;
          	cout << n << " " << h << " " << w;
          	return 0;
        }
    }
  }
}