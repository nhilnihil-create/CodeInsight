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


	//これも解説みないと全くわからないなぁ

	int N;
	cin >> N;

	vector<pair<int, int>> eda[100000];

	rep1(i, N - 1) {
		if (i % 10 != 9) {
			int A = (i + 1) % N;
			eda[i].push_back(make_pair(A, 1));
		}
		int B = (i * 10) % N;
		eda[i].push_back(make_pair(B, 0));
	}

	int D[100000] = {};
	vector<pair<int, int>> que;

	que.push_back(make_pair(1, 1));

	rep(i, N) {
		vector<pair<int, int>> que2;
		for (pair<int, int> itr : que) {
			if (D[itr.first] == 0 || D[itr.first] > itr.second) {
				for (pair<int, int> itr2 : eda[itr.first]) {
					que2.push_back(make_pair(itr2.first, itr.second + itr2.second));
				}
				D[itr.first] = itr.second;
			}
		}
		que = que2;
	}

	co(D[0]);

	Would you please return 0;
}