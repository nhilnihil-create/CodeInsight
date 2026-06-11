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

	int kumi = 0;
	rep1(i, 1000) {
		if ((i - 1) * i / 2 == N) {
			kumi = i;
			break;
		}
	}
	if (kumi == 0) {
		co("No");
	}
	else {
		co("Yes");
		co(kumi);
		string S[1000];
		rep(i, kumi) S[i] = to_string(kumi - 1);

		int k1 = 0;
		int k2 = 0;
		rep1(i, N) {
			k2++;
			if (k2 >= kumi) {
				k1++;
				k2 = k1 + 1;
			}
			S[k1] += " " + to_string(i);
			S[k2] += " " + to_string(i);
		}
		rep(i, kumi) co(S[i]);
	}

	Would you please return 0;
}