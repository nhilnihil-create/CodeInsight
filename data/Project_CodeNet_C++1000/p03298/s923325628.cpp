#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>

using namespace std;

typedef long long ll;

map<pair<string, string>, ll> leftMap, rightMap;

int main() {
	int n;
	string s;
	cin >> n >> s;

	string leftS, rightS;
	for (int i = 0; i < n; i++)leftS.push_back(s[i]);
	for (int i = 2 * n - 1; i >= n; i--)rightS.push_back(s[i]);

	for (int i = 0; i < (1 << n); i++) {
		string f, s;
		if (i & 1) {
			for (int j = 0; j < n; j++)
				if((i >> j) & 1)f.push_back(leftS[j]);
				else s.push_back(leftS[j]);
		}
		else {
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1)s.push_back(leftS[j]);
				else f.push_back(leftS[j]);
		}
		leftMap[make_pair(f, s)]++;
	}

	for (int i = 0; i < (1 << n); i++) {
		string f, s;
		if (i & 1) {
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1)f.push_back(rightS[j]);
				else s.push_back(rightS[j]);
		}
		else {
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1)s.push_back(rightS[j]);
				else f.push_back(rightS[j]);
		}
		rightMap[make_pair(f, s)]++;
	}

	ll ans = 0;
	for (auto it = leftMap.begin(); it != leftMap.end(); it++) {
		auto tmp = (*it).first;
		ans += (rightMap[make_pair(tmp.second, tmp.first)] + rightMap[make_pair(tmp.first, tmp.second)]) * (*it).second / 4;
	}
	ans *= 2LL;
	cout << ans  << "\n";
	return 0;
}