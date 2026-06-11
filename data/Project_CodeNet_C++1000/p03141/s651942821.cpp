#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N;
	cin >> N;

	vector < tuple<ll, ll, ll> > A;
	vector < tuple<ll, ll, ll> > B;

	for (ll ii = 0; ii < N; ++ii){
		ll a, b;
		cin >> a >> b;
		tuple<ll, ll, ll> aa = make_tuple(a + b, a, ii);
		tuple<ll, ll, ll> bb = make_tuple(b + a, b, ii);
		A.push_back(aa);
		B.push_back(bb);
	}

	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());

	// for (int ii = 0; ii < N; ++ii){
	// 	printf("a[%i] %lld\n", ii, get<0>(A[ii]));
	// }
	// for (int ii = 0; ii < N; ++ii){
	// 	printf("b[%i] %lld\n", ii, get<0>(B[ii]));
	// }

	ll acnt = 0;
	ll bcnt = 0;
	ll asum = 0;
	ll bsum = 0;
	vector <bool> ok(N, true);
	for (int ii = 0; ii < N; ++ii){
		if (ii % 2 == 0){	//たかはしのターン
			while(true) {
				ll idx = get<2>(A[acnt]);
				if (ok[idx]){
					break;
				} else {
					acnt++;
				}
			}
			asum += get<1>(A[acnt]);
			ll idx = get<2>(A[acnt]);
			ok[idx] = false;
			acnt++;
			// printf("asum %lld, idx %lld\n",asum, idx);
		} else {	//あおきのターン
			while(true) {
				ll idx = get<2>(B[bcnt]);
				if (ok[idx]){
					break;
				} else {
					bcnt++;
				}
			}
			bsum += get<1>(B[bcnt]);
			ll idx = get<2>(B[bcnt]);
			ok[idx] = false;
			bcnt++;
			// printf("bsum %lld, idx %lld\n",bsum, idx);
		}
	}

	cout << asum - bsum << "\n";		

	return 0;
}
