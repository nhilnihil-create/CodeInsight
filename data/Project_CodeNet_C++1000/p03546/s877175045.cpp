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
  ll H, W, res = 0; cin >> H >> W;
  vector<vector<ll>> c(10, vector<ll>(10)), A(H, vector<ll>(W));
  rep(i, 0, 10) {
  	rep(j, 0, 10) {
    	cin >> c[i][j];
    }
  }
  rep(i, 0, H) {
  	rep(j, 0, W) {
    	cin >> A[i][j];
    }
  }
  rep(k, 0, 10) {
  	rep(i, 0, 10) {
  		rep(j, 0, 10) {
    		if (c[i][j] > c[i][k] + c[k][j])
              c[i][j] = c[i][k] + c[k][j];
    	}
  	}
  }
  rep(i, 0, H) {
  	rep(j, 0, W) {
    	if (A[i][j] >= 0) res += c[A[i][j]][1];
    }
  }
  cout << res << endl;
}