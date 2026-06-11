#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;
using lli = long long int;
using tiiii = std::tuple<lli, lli, lli, lli>;
using pii = std::pair<int, int>;
using vpii = std::vector<pii>;

vpii A[100001];

lli P[100001];

bool B[100001] = {};

int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		P[i] = numeric_limits<lli>().max();
	}

	for (int i = 0; i < M; i++) {
		int l, r, d;
		std::cin >> l >> r >> d;

		A[l - 1].push_back({ r - 1,d });
		A[r - 1].push_back({ l - 1,-1 * d });
	}

	std::queue<int> q;
	for (int i = 0; i < N; i++) {
		q.push(i);

		while (!q.empty()) {
			int i = q.front();
			q.pop();
			if (!B[i]) {
				B[i] = true;
				if (P[i] == numeric_limits<lli>().max()) {
					P[i] = 0;
				}

				for (int j = 0; j < A[i].size(); j++) {
					if (P[A[i][j].first] == numeric_limits<lli>().max()) {
						P[A[i][j].first] = P[i] + A[i][j].second;
					}
					else {
						if (P[A[i][j].first] != P[i] + A[i][j].second) {
							std::cout << "No" << endl;
							return 0;
						}
					}
					q.push(A[i][j].first);
				}
			}
		}
	}
	std::cout << "Yes" << std::endl;

	return 0;
}