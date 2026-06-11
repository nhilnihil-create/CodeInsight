#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

string sub(int n) {
	string ret = "";
	string num = to_string(n);
	for (int i = 0; i < 6 - num.size(); i++) {
		ret += '0';
	}
	return ret + num;
}

int binarySearch(vector<int> vec, int key) {
	int L, R, M;
	L = 0;
	R = vec.size();
	M = (L + R) / 2;
	while (L <= R) {
		if (vec[M] == key) {
			return ++M;
		}
		else if (key < vec[M]) {
			R = M;
			M= (L + R) / 2;
		}
		else {
			L = M + 1;
			M = (L + R) / 2;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	struct Info {
		int p;
		int y;
	};

	vector<struct Info> v(M);
	vector<vector<int>> prf(N, vector<int>(0));

	for (int i = 0; i < M; i++) {
		int P, Y;
		cin >> P >> Y;
		v.at(i).p = P;
		v.at(i).y = Y;
		prf.at(P - 1).push_back(Y);
	}

	for (int i = 0; i < N; i++) {
		sort(prf.at(i).begin(), prf.at(i).end());
	}

	for (int i = 0; i < M; i++) {
		int P, Y;
		P = v.at(i).p;
		Y = v.at(i).y;
		//cout << P << ' ' << Y << endl;
		int n = binarySearch(prf.at(P - 1), Y);
		cout << sub(P) << sub(n) << endl;
	}
}