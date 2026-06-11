#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <ctime>
#include <random>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-9
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;

int main() {
	speed;
	int n, t, a, h;
	double best = inf;
	int ans = 0;
	cin >> n >> t >> a;
	for (int i = 0; i < n; ++i) {
		cin >> h;
		double ct = (double)t - h * 0.006;
		if (abs(ct - a) < best)
			best = abs(ct - a), ans = i;
	}
	cout << ans + 1;
}