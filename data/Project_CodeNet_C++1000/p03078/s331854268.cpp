#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll X, Y, Z, K;
	cin >> X >> Y >> Z >> K;

	vector <ll> A(X);
	for (int ii = 0; ii < X; ++ii){
		cin >> A[ii];
	}
	vector <ll> B(Y);
	for (int ii = 0; ii < Y; ++ii){
		cin >> B[ii];
	}
	vector <ll> C(Z);
	for (int ii = 0; ii < Z; ++ii){
		cin >> C[ii];
	}
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
		if (m[idx] == 0){
			cout << val << "\n";
		}
		m[idx] = 1;

		ll aidx = idx / cA;
		ll bidx = (idx - cA*aidx) / cB;
		ll cidx = idx - cA*aidx - cB*bidx;

		if (aidx + 1 < X){
			ll taidx = aidx + 1;
			//下位互換でないかチェック
			bool ok = true;
			for (int ii = 0; ii < v.size(); ++ii){
				ll vidx = v[ii].second;
				ll vaidx = vidx / cA;
				ll vbidx = (vidx - cA*vaidx) / cB;
				ll vcidx = vidx - cA*vaidx - cB*vbidx;
				// if ( (taidx<=vaidx) && (bidx<=vbidx) && (cidx<=vcidx)){
				// 	ok = false;
				// 	break;
				// }
			}
			if (ok){
				ll val = A[taidx] + B[bidx] + C[cidx];
				ll idx = cA*taidx + cB*bidx + cC*cidx;
				if (mm[idx] == 0){
					v.push_back(make_pair(val, idx));
					mm[idx] = 1;
				}
				// printf("valA %i, idx %i %i %i\n", val, taidx, bidx, cidx);
			}
		}

		if (bidx + 1 < Y){
			ll tbidx = bidx + 1;
			//下位互換でないかチェック
			bool ok = true;
			for (int ii = 0; ii < v.size(); ++ii){
				ll vidx = v[ii].second;
				ll vaidx = vidx / cA;
				ll vbidx = (vidx - cA*vaidx) / cB;
				ll vcidx = vidx - cA*vaidx - cB*vbidx;
				// if ( (aidx<=vaidx) && (tbidx<=vbidx) && (cidx<=vcidx)){
				// 	ok = false;
				// 	break;
				// }
			}
			if (ok){
				ll val = A[aidx] + B[tbidx] + C[cidx];
				ll idx = cA*aidx + cB*tbidx + cC*cidx;
				if (mm[idx] == 0){
					v.push_back(make_pair(val, idx));
					mm[idx] = 1;
				}
			}
		}

		if (cidx + 1 < Z){
			ll tcidx = cidx + 1;
			//下位互換でないかチェック
			bool ok = true;
			for (int ii = 0; ii < v.size(); ++ii){
				ll vidx = v[ii].second;
				ll vaidx = vidx / cA;
				ll vbidx = (vidx - cA*vaidx) / cB;
				ll vcidx = vidx - cA*vaidx - cB*vbidx;
				// if ( (aidx<=vaidx) && (bidx<=vbidx) && (tcidx<=vcidx)){
				// 	ok = false;
				// 	break;
				// }
			}
			if (ok){
				ll val = A[aidx] + B[bidx] + C[tcidx];
				ll idx = cA*aidx + cB*bidx + cC*tcidx;
				if (mm[idx] == 0){
					v.push_back(make_pair(val, idx));
					mm[idx] = 1;
				}
			}
		}

		sort(v.begin(), v.end());
	}

	return 0;
}
