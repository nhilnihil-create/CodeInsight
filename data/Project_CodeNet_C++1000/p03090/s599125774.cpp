#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
#include <iomanip>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60
const double PI = 3.14159265358979323846;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	if (N % 2 == 0) {
		cout << N * (N - 2) / 2 << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (i + j != N + 1) cout << i << " " << j << endl;
			}
		}
	}
	else { 
		cout << (N - 1) * (N - 1) / 2 << endl;
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (i + j != N) cout << i << " " << j << endl;
			}
		}
		for (int i = 1; i < N; i++) cout << i << " " << N << endl;
	}

	return 0;
}