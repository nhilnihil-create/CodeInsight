#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

	ll A, B, Q;
	cin >> A >> B >> Q;

	vector<ll> s(A);
	vector<ll> t(B);

	vector<ll> x(Q);

	for(int i = 0; i < A; i++) {
		cin >> s[i];
	}

	for(int i = 0; i < B; i++) {
		cin >> t[i];
	}

	for(int i = 0; i < Q; i++) {
		cin >> x[i];
	}

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	for(int i = 0; i < Q; i++) {
		ll xs = lower_bound(s.begin(), s.end(), x[i]) - s.begin();
		ll xt = lower_bound(t.begin(), t.end(), x[i]) - t.begin();

		//cerr << "xs " << xs << endl;
		//cerr << "xt " << xt << endl;

		ll m = 100000000000;

		if(xs < A && xt < B)
			m = max(s[xs], t[xt]) - x[i];
		if(0 <= xs - 1LL && 0 <= xt - 1LL)
			m = min(m, x[i] - min(s[xs - 1LL], t[xt - 1LL]));
		if(0 <= xs - 1LL && xt < B) {
			m = min(m, t[xt] + x[i] - s[xs - 1LL] * 2LL);
			m = min(m, t[xt] * 2LL - s[xs - 1LL] - x[i]);
		}
		if(0 <= xt - 1LL && xs < A) {
			m = min(m, s[xs] + x[i] - t[xt - 1LL] * 2LL);
			m = min(m, s[xs] * 2LL - t[xt - 1LL] - x[i]);
		}

		cout << m << endl;
	}
}