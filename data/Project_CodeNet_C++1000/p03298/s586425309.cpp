#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define Would
#define you
#define please

int main() {
	
	//解説PDFを見ました(迫真)

	int N;
	string S;
	cin >> N >> S;

	map<string, int> GODmae, GODato;

	rep(i, 1 << N) {
		string blue = "";
		string red = "";
		string blue2 = "";
		string red2 = "";
		rep(ii, N) {
			if ((i >> ii & 1) == 1) {
				blue += S.substr(ii, 1);
				blue2 += S.substr(2 * N - ii - 1, 1);
			}
			else {
				red += S.substr(ii, 1);
				red2 += S.substr(2 * N - ii - 1, 1);
			}
		}
		GODmae[blue + "," + red]++;
		GODato[blue2 + "," + red2]++;
	}

	long long kotae = 0;
	for (auto itr : GODmae) kotae += 1ll * GODmae[itr.first] * GODato[itr.first];
	cout << kotae << "\n";
	Would you please return 0;
}
