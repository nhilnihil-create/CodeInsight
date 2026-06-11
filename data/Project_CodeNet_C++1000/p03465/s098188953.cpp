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

	
	int N;
	cin >> N;
	int A[2000];
	int B[2001] = {};
	int goukei = 0;
	rep(i, N) {
		cin >> A[i];
		goukei += A[i];
		B[A[i]]++;
	}
	int hanbun = (goukei + 1) / 2;

	vector<int> V(4000001);
	V[0] = 1;
	int saidai = 0;
	rep1(i, 2000) {
		if (B[i]) {
			for (int j = saidai; j >= 0; j--) {
				if (V[j]) {
					rep1(k, B[i]) V[j + k * i] = 1;
					
				}
			}
			saidai += B[i] * i;
		}
		if (V[hanbun]) {
			co(hanbun);
			return 0;
		}
	}

	for (int i = hanbun; i < 4000000; i++) {
		if (V[i]) {
			co(i);
			break;
		}
	}

	Would you please return 0;
}