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
	int ans = (n + 1) / 2;
	const int c = S[ans - 1];
	for (size_t i = 0; i < n / 2; i++)
	{
		if (S[n - 1 - ans] != c || S[ans] != c)
			break;
		ans++;
	}
	cout << ans << endl;
}