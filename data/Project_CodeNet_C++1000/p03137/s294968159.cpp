#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <set>

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }
ll MOD = 1000000007;

int main() {
	int N, M, x;
	cin >> N >> M;
	vector<int> X(M), D(M - 1);
	for (auto& x : X)cin >> x;
	sort(X.begin(), X.end());
	for (int i = 0; i < M - 1; i++)D[i] = X[i + 1] - X[i];
	sort(D.begin(), D.end());
	ll ans = 0;
	for (int i = 0; i < M - N; i++)ans += D[i];
	print(ans);
}
