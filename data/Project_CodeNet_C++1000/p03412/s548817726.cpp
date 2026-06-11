#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
	ll N;
	cin >> N;
	vector<ll> a(N), b(N);
	REP(i, N) cin >> a[i];
	REP(i, N) cin >> b[i];
	vector<ll> c(N), d(N);
	vector<ll> bits(30);
	REP(k, 30){

		//printf("k: %d\n", k);

		ll res = 0;
		REP(i, N){
			c[i] = a[i]%(1<<(k+1));
			d[i] = b[i]%(1<<(k+1));
		}
		sort(d.begin(), d.end());

		/*
		REP(i, N){
			cout << c[i] << " ";
		}
		cout << endl;
		REP(i, N){
			cout << d[i] << " ";
		}
		cout << endl;
		*/

		ll T = (1<<k);
		REP(i, N){
			ll res1 = (lower_bound(d.begin(), d.end(), 2*T-c[i]) - lower_bound(d.begin(), d.end(), T-c[i]));
			ll res2 =  (lower_bound(d.begin(), d.end(), 4*T-c[i]) - lower_bound(d.begin(), d.end(), 3*T-c[i]));
			res += res1;
			res += res2;
		}
		bits[k] = (res%2);
	}

	ll ans = 0;
	REP(k, 30){
		ans += (bits[k]*(1<<k));
	}
	cout << ans << endl;
    return 0;
}