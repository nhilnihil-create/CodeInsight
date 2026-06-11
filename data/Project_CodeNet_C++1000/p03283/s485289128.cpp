#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int d[510][510];
int main()
{
	int N, M, Q;
	cin >> N >> M >> Q;
	for (int i = 0; i < M; i++) {
		int L, R;
		cin >> L >> R;
		L--; R--;
		d[L][R]++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			d[i][j] += d[i][j - 1];
		}
	}
	for (int j = 0; j < N; j++) {
		for (int i = N - 2; i >= 0; i--) {
			d[i][j] += d[i + 1][j];
		}
	}
	while (Q--) {
		int p, q;
		cin >> p >> q;
		p--; q--;
		cout << d[p][q] << endl;
	}
}
