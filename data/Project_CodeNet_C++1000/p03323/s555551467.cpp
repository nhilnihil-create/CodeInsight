#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <tuple>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for(int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 0x3b9aca07;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int a, b; cin >> a >> b;
	if (a <= 8 && b <= 8) cout << "Yay!";
	else cout << ":(";
	cout << endl;
	return 0;
}
