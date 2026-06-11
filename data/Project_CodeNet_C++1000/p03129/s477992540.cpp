#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long ll;

int main() {
	int n, k; cin >> n >> k;
	puts((n + 1) / 2 >= k ? "YES" : "NO");
	return 0;
}
