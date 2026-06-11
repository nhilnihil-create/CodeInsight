#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <random>
using namespace std;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	long long int res = 0;
	vector<pair<long long int, long long int>> v;
	// first = delicious second = type
	for (int i = 0; i < n; i++) {
		long long int a, b;
		cin >> a >> b;
		v.push_back(make_pair(b, a));
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	long long int c = 0;
	unordered_map<long long int, int> um;
	for (int i = 0; i < k; i++) {
		c += v[i].first;
		um[v[i].second]++;
	}
	long long int s = um.size();
	res = c + s * s;
	int index1 = k - 1, index2 = k;
	while (index1 >= 0 && index2 < v.size()) {
		while (index1 >= 0 && um[v[index1].second] <= 1) {
			index1--;
		}
		while (index2 < v.size() && um.find(v[index2].second) != um.end()) {
			index2++;
		}
		if (index1 < 0 || index2 >= v.size())
			break;
		c = c - v[index1].first + v[index2].first;
		um[v[index1].second]--;
		um[v[index2].second]++;
		s = um.size();
		res = max(res, c + s * s);
		index1--;
		index2++;
	}
	cout << res << endl;
}












