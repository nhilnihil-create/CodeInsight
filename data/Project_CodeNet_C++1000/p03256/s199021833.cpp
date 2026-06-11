#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define Would
#define you
#define please

int main() {
	//おまじない
	cin.tie(0);
	ios::sync_with_stdio(false);



	int N, M, a[200001], b[200001];
	string S;
	vector<int> henn[200001];
	cin >> N >> M >> S;
	rep1(i, M) {
		cin >> a[i] >> b[i];
		henn[a[i]].push_back(b[i]);
		henn[b[i]].push_back(a[i]);
	}


	int bosshuu[200001] = {};
	//int ikeruB[200000] = {};

	int hetta = 1;
	int checkzumi[200001] = {};
	vector<int> youcheck;
	rep1(i, N) youcheck.push_back(i);

	while (hetta) {
		hetta = 0;
		vector<int> youcheck2;

		for(int i: youcheck) {
			if (bosshuu[i] == 0) {
				int ikeruA = 0;
				int ikeruB = 0;
				for (int ii = 0; ii < henn[i].size(); ii++) {
					if (bosshuu[henn[i][ii]] == 0) {
						if (S[henn[i][ii] - 1] == 'A') ikeruA = 1;
						else ikeruB = 1;
					}
					else {
						henn[i].erase(henn[i].begin() + ii);
						ii--;
					}
				}
				if (ikeruA == 0 || ikeruB == 0) {
					bosshuu[i] = 1;
					hetta++;
					rep(ii, henn[i].size()) youcheck2.push_back(henn[i][ii]);
				}
			}
		}
		youcheck.erase(youcheck.begin(), youcheck.end());
		for (int i: youcheck2) youcheck.push_back(i);
	}

	int kotae = 0;
	rep1(i, N) if (bosshuu[i] == 0) kotae = 1;

	if (kotae == 1) cout << "Yes" << "\n";
	else cout << "No" << "\n";
	Would you please return 0;
}