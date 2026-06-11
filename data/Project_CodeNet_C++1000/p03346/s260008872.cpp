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

int A[200009];
int B[200009];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) B[A[i]] = i;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int num = B[i];
		int cnt = 1;
		while (i < N && B[i] < B[i + 1]) {
			num = B[i + 1];
			i++;
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << N - ans << endl;

	return 0;
}