#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int B = 29;
unordered_map<long long, long long> mp;
long long ans;
string tmp;
int n;
long long ho(string &a, string &b) {
	long long h1 = 0, h2 = 0;
	for (int i = 0; i < a.size(); i++)
		h1 = h1 * B + a[i] - 'a' + 1;
	for (int i = 0; i < b.size(); i++)
		h2 = h2 * (B + 2) + b[i] - 'a' + 1;
	return (h1 * h2 + h1 + 2 * h2);
}

int main() {
	cin >> n >> tmp;
	for (int i = 0; i < (1 << n); i++) {
		string r1, r2;
		for (int j = 0; j < n; j++)
			if ((i & (1 << j)) != 0)
				r1.push_back(tmp[n + j]);
			else
				r2.push_back(tmp[n + j]);
		reverse(r2.begin(), r2.end());
		mp[ho(r1, r2)]++;
	}
	for (int i = 0; i < (1 << n); i++) {
		string r1, r2;
		for (int j = 0; j < n; j++)
			if ((i & (1 << j)) != 0)
				r1.push_back(tmp[j]);
			else
				r2.push_back(tmp[j]);
		reverse(r2.begin(), r2.end());
		ans += mp[ho(r2, r1)];
	}
	cout << ans;
}