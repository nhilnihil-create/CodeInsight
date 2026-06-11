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

	if (N == 3) {
		cout << "2 3 25" << endl;
	}
	else {
		if (N == 4) cout << "2 3 9 10";
		else if (N == 5) cout << "2 3 6 9 10";
		else if (N == 6) cout << "2 3 4 8 9 10";
		else {
			cout << "2 3 4 8 9 10";
			N -= 6;
			int k = N / 2;
			if (k > 7497) k = 7497;
			N -= k * 2;

			int A[3][2] = { 2,10,3,9,4,8 };
			rep(i, k) {
				cout << " " << 12 * (i / 3 + 1) + A[i % 3][0];
				cout << " " << 12 * (i / 3 + 1) + A[i % 3][1];
			}
			rep1(i, N) cout << " " << 6 * i;
		}
		cout << endl;
	}

	Would you please return 0;
}