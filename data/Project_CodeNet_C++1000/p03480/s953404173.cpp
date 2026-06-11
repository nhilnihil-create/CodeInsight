#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>
using ll = long long;
using namespace std;

string S;

int main() {
	cin >> S;
	size_t n = S.size();
	int ans;
	if (n % 2 == 0) {
		ans = n / 2;
	}
	else {
		ans = (n + 1) / 2;
	}
	const int c = S[ans - 1];
	for (size_t i = 0; i < n / 2; i++)
	{
		if (S[n - ans - 1] == c && S[ans] == c) {
			ans++;
		}
		else {
			break;
		}
	}
	cout << ans << endl;;
}