#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	int N;
	cin >> N;
	if (N == 3) {
		cout << 2 << endl;
		cout << "1 3" << endl;
		cout << "2 3" << endl;
		return 0;
	}

	if (N % 2 == 1) {
		vector<vector<int>> a(N / 2);
		for (int i = 1; i <= N / 2; i++) {
			a[i - 1].push_back(i);
			a[i - 1].push_back(N - i);
		}
		a.push_back(vector<int>());
		a.back().push_back(N);

		set<pair<int, int>> e;
		for (int i = 0; i < a[0].size(); i++)for (int j = 0; j < a.back().size(); j++) {
			e.insert({ min(a[0][i],a.back()[j]), max(a[0][i],a.back()[j])});
		}
		for (int i = 0; i < a.size() - 1; i++) {
			for (int j = 0; j < a[i].size(); j++)for (int k = 0; k < a[i + 1].size(); k++) {
				e.insert({ min(a[i][j],a[i + 1][k]), max(a[i][j],a[i + 1][k]) });
			}
		}

		cout << e.size() << endl;
		for (auto itr = e.begin(); itr != e.end(); itr++) {
			cout << (*itr).first << " " << (*itr).second << endl;
		}
	}
	else {
		vector<vector<int>> a(N / 2);
		for (int i = 1; i <= N / 2; i++) {
			a[i - 1].push_back(i);
			a[i - 1].push_back(N - i + 1);
		}

		set<pair<int, int>> e;
		for (int i = 0; i < a[0].size(); i++)for (int j = 0; j < a.back().size(); j++) {
			e.insert({ min(a[0][i],a.back()[j]), max(a[0][i],a.back()[j]) });
		}
		for (int i = 0; i < a.size() - 1; i++) {
			for (int j = 0; j < a[i].size(); j++)for (int k = 0; k < a[i + 1].size(); k++) {
				e.insert({ min(a[i][j],a[i + 1][k]), max(a[i][j],a[i + 1][k]) });
			}
		}

		cout << e.size() << endl;
		for (auto itr = e.begin(); itr != e.end(); itr++) {
			cout << (*itr).first << " " << (*itr).second << endl;
		}
	}
}