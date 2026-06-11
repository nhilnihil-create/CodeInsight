#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	
	int N, K, Q;
	cin >> N >> K >> Q;
	int A[2000];
	set<int> ST;
	rep(i, N) {
		cin >> A[i];
		ST.insert(A[i]);
	}

	int saishou = 1e9;
	for (int i : ST) {
		vector<int> V, V2;
		rep(j, N) {
			if (A[j] < i) {
				if (V2.size() >= K) {
					sort(V2.begin(), V2.end());
					int kari = V2.size();
					rep(k, kari - K + 1) V.pb(V2[k]);
				}
				V2.clear();
			}
			else {
				V2.pb(A[j]);
			}
		}
		sort(V2.begin(), V2.end());
		int kari = V2.size();
		rep(k, kari - K + 1) V.pb(V2[k]);

		if (V.size() >= Q) {
			sort(V.begin(), V.end());
			saishou = min(saishou, V[Q - 1] - i);
		}
	}

	co(saishou);

	Would you please return 0;
}