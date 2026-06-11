#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll X, Y, Z, K;
	cin >> X >> Y >> Z >> K;

	vector <ll> th(3);
	th[0] = X; 	th[1] = Y; 	th[2] = Z;

	vector <ll> A(X);
	for (int ii = 0; ii < X; ++ii) cin >> A[ii];
	vector <ll> B(Y);
	for (int ii = 0; ii < Y; ++ii) cin >> B[ii];
	vector <ll> C(Z);
	for (int ii = 0; ii < Z; ++ii) cin >> C[ii];
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	sort(C.rbegin(), C.rend());

	vector < pair<ll, ll> > v;
	ll cA = 1000000;
	ll cB = 1000;
	ll cC = 1;
	ll pval = A[0] + B[0] + C[0];
	ll pidx = cA*0 + cB*0 + cC*0;
	v.push_back(make_pair(pval, pidx));

	map<ll, ll> m;
	map<ll, ll> mm;
	mm[pidx] = 1;

	for (int cnt = 0; cnt < K; ++cnt){
		pair<ll, ll> tmp = v.back();
		v.pop_back();

		ll val = tmp.first;
		ll idx = tmp.second;
		if (m[idx] == 0) cout << val << "\n";

		m[idx] = 1;

		vector <ll> tidx(3);
		tidx[0] = idx / cA;
		tidx[1] = (idx - cA*tidx[0]) / cB;
		tidx[2] = idx - cA*tidx[0] - cB*tidx[1];
		for (int ii = 0; ii < 3; ++ii){
			if (tidx[ii] + 1 == th[ii]) continue;
			tidx[ii]++;
			ll val = A[tidx[0]] + B[tidx[1]] + C[tidx[2]];
			ll idx = cA*tidx[0] + cB*tidx[1] + cC*tidx[2];
			if (mm[idx] == 0){
				v.push_back(make_pair(val, idx));
				mm[idx] = 1;
			}
			tidx[ii]--;
		}

		sort(v.begin(), v.end());
	}

	return 0;
}
