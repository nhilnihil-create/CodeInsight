#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

#define p(a, b) make_pair(a, b)

const int use[10] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int dp[10][10001];
bool f[10][10001];

bool order(int& a, int& b) { return use[a] != use[b] ? use[a] < use[b] : a > b; }

int main()
{
	int N, M, a;
	vector<int> A;

	cin >> N >> M;
	rep(i, M) {
		cin >> a;
		A.push_back(a);
	}

	sort(A.begin(), A.end(), order);

	/* マッチ本数同じで小さい数は不要なので削除 */
	vector<int>::iterator it = A.begin(); it++;
	int previous = use[A.front()];
	while (it != A.end()) {
		if (use[*it] == previous) it = A.erase(it);
		else { previous = use[*it]; it++; }
	}
	M = A.size();

	if (M == 1) {
		int num = N / use[A[0]];
		rep(i, num) cout << A[0];
		cout << endl;
		return 0;
	}

	sort(A.begin(), A.end());

	rep(i, M) {
		repc(j, 1, N) {
			if (i == 0) {
				if (j % use[A[i]] == 0) {
					dp[i][j] = j / use[A[i]];
					f[i][j] = true;
				}
				continue;
			}

			dp[i][j] = dp[i - 1][j];
			if (j % use[A[i]] == 0 && dp[i][j] <= j / use[A[i]]) {
				dp[i][j] = j / use[A[i]];
				f[i][j] = true;
			}
			if (j > use[A[i]] && dp[i][j - use[A[i]]] != 0 && dp[i][j] <= dp[i][j - use[A[i]]] + 1) {
				dp[i][j] = dp[i][j - use[A[i]]] + 1;
				f[i][j] = true;
			}
		}
	}

	int num = M - 1;

	while (N > 0) {
		if (!f[num][N]) num--;
		else {
			cout << A[num];
			N -= use[A[num]];
		}
	}

	cout << endl;

	return 0;
}
