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

	
	string S;
	cin >> S;

	int SS = S.size();
	int SH = SS / 2;

	int kotae;

	if (SS % 2) {
		int base = S[SH];
		int tuika = 0;
		rep1(i, SH) {
			if (S[SH + i] != base || S[SH - i] != base) break;
			else tuika++;
		}

		kotae = SH + 1 + tuika;
	}
	else {
		int base = S[SH];
		int tuika = 0;
		rep1(i, SH) {
			if (S[SH + i - 1] != base || S[SH - i] != base) break;
			else tuika++;
		}

		kotae = SH + tuika;
	}

	co(kotae);
	Would you please return 0;
}