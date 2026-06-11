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

	int N;
	cin >> N;

	int a[51] = {};
	int saidai = -10000000, saishou = 10000000;
	int saidaii, saishoui;

	rep1(i, N) {
		cin >> a[i];
		if (saidai < a[i]) {
			saidai = a[i];
			saidaii = i;
		}
		if (saishou > a[i]) {
			saishou = a[i];
			saishoui = i;
		}
	}
	vector<pair<int, int>> kotae;
	
	if (saidai + saishou >= 0) {

		rep1(i, N) kotae.push_back(make_pair(saidaii, i));
		rep1(i, N - 1) kotae.push_back(make_pair(i, i + 1));

	}
	else {

		rep1(i, N) kotae.push_back(make_pair(saishoui, i));
		rep(i, N - 1) kotae.push_back(make_pair(N - i, N - 1 - i));

	}

	co(2 * N - 1);
	rep(i, kotae.size()) {
		cosp(kotae[i].first);
		co(kotae[i].second);
	}
	Would you please return 0;
}