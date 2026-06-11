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

	bitset<4000001> BS;
	BS[0] = true;
	rep(i, N) {
		BS |= BS << A[i];
		if (BS[hanbun]) {
			co(hanbun);
			return 0;
		}
	}

	for (int i = hanbun; i < 4000000; i++) {
		if (BS[i]) {
			co(i);
			break;
		}
	}

	Would you please return 0;
}