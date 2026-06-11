#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int>zero,one;
	if (s.at(0) == '0')one.push_back(0);
	for (int i = 0; i < s.length(); i++) {
		if (i == 0) {
			if (s.at(0) == '0')zero.push_back(1);
			else one.push_back(1);
		}
		else {
			if (s.at(i - 1) == s.at(i)) {
				if (s.at(i) == '0')zero.at(zero.size() - 1)++;
				else one.at(one.size() - 1)++;
			}
			else {
				if (s.at(i) == '0')zero.push_back(1);
				else one.push_back(1);
			}
		}
	}
	if (s.at(s.length() - 1) == '0')one.push_back(0);
	if (zero.size() <= k) {
		cout << n << endl;
		return 0;
	}
	vector<int>zerosig = { 0 };
	vector<int>onesig = { 0 };
	for (int i = 0; i < zero.size(); i++) zerosig.push_back(zerosig.at(i) + zero.at(i));
	for (int i = 0; i < one.size(); i++)onesig.push_back(onesig.at(i) + one.at(i));
	ll ans = 0;
	/*for (int i = 0; i < zerosig.size(); i++)cout << zerosig.at(i) << " ";
	cout << endl;
	for (int i = 0; i < onesig.size(); i++)cout << onesig.at(i) << " ";
	cout << endl;*/
	for (int i = 0; i < zerosig.size() - k; i++) {
		ll res = zerosig.at(i + k) - zerosig.at(i) + onesig.at(i + k + 1) - onesig.at(i);
		ans = max(ans, res);
	}
	cout << ans << endl;
}