#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define Would
#define you
#define please

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	pair<int, int> LN[100000], RN[100000];

	rep(i, N) {
		int L, R;
		cin >> L >> R;
		LN[i] = make_pair(L, i);
		RN[i] = make_pair(R, i);
	}
	sort(LN, LN + N);
	sort(RN, RN + N);
	reverse(LN, LN + N);

	ll best = -1e18;
	rep(k, 2) {

		int tukatta[100000] = {};

		ll kyori = 0;
		int ichi = 0;
		int Ltugi = 0;
		int Rtugi = 0;

		rep(j, N) {
			if (k || j) {
				for (int i = Ltugi; i < N; i++) {
					if (ichi < LN[i].first && tukatta[LN[i].second] == 0) {
						kyori += LN[i].first - ichi;
						ichi = LN[i].first;
						cesp(ichi);
						ce(kyori);
						tukatta[LN[i].second] == 1;
						Ltugi++;
						break;
					}
					Ltugi++;
				}
			}
			for (int i = Rtugi; i < N; i++) {
				if (ichi > RN[i].first && tukatta[RN[i].second] == 0) {
					kyori += ichi - RN[i].first;
					ichi = RN[i].first;
					cesp(ichi);
					ce(kyori);
					tukatta[RN[i].second] == 1;
					Rtugi++;
					break;
				}
				Rtugi++;
			}
		}
		kyori += abs(ichi);
		best = max(best, kyori);
	}
	co(best);

	Would you please return 0;
}