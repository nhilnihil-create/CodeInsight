#include<bits/stdc++.h>
using namespace std;
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

	map<string, int> GOD;

	rep(i, 1 << N) {
		string blue;
		string red;
		rep(ii, N) {
			if (i >> ii & 1) {
				blue += S[ii];
			}
			else {
				red += S[ii];
			}
		}
		GOD[blue + "," + red]++;
	}
	long long kotae = 0;
	rep(i, 1 << N) {
		string blue2;
		string red2;
		rep(ii, N) {
			if (i >> ii & 1) {
				blue2 += S[2 * N - ii - 1];
			}
			else {
				red2 += S[2 * N - ii - 1];
			}
		}
		kotae += GOD[blue2 + "," + red2];
	}
	cout << kotae << "\n";
	Would you please return 0;

}
