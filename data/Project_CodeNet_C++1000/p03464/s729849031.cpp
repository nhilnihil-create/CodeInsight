#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

ll mod = 1e9+7;

ll gcd(ll a, ll b){
  	if(b == 0){
    	return a;
  	}
  	return gcd(b, a % b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

	ll k;
	cin >> k;
	vll a(k);
	REP(i, k) cin >> a[i];

	//dp[i] : i ターン終了後の最小/最大人数
	vll dpmin(k + 1), dpmax(k + 1);
	dpmin[k] = dpmax[k] = 2;

	REPR(i, k){
		dpmin[i] = ((dpmin[i + 1] - 1) / a[i] + 1) * a[i];
		dpmax[i] = (dpmax[i + 1] / a[i]) * a[i] + a[i] - 1;
		if(dpmin[i] > dpmax[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << dpmin[0] << " " << dpmax[0] << endl;
    return 0;
}