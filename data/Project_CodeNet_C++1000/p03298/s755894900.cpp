#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define Would
#define you
#define please

int main() {
	
	//解説PDFを見ました(迫真)
	//速度の様子うかがい

	int N;
	string S;
	cin >> N >> S;

	map<pair<ll, ll>, int> GOD;

	rep(i, 1 << N) {
		ll blue = 0;
		ll red = 0;
		rep(ii, N) {
			if (i >> ii & 1) {
				blue = blue * 27 + S[ii] - 'a' + 1;
			}
			else {
				red = red * 27 + S[ii] - 'a' + 1;
			}
		}
		GOD[make_pair(blue, red)]++;
	}
	ll kotae = 0;
	rep(i, 1 << N) {
		ll blue = 0;
		ll red = 0;
		rep(ii, N) {
			if (i >> ii & 1) {
				blue = blue * 27 + S[2 * N - ii - 1] - 'a' + 1;
			}
			else {
				red = red * 27 + S[2 * N - ii - 1] - 'a' + 1;
			}
		}
		kotae += GOD[make_pair(blue, red)];
	}
	cout << kotae << "\n";
	Would you please return 0;

}
