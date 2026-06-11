#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;
int main() {
	vector<int> a(10);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			if (s[j] == 'T' || s[j] == 'G' || s[j] == 'A' || s[j] == 'C')a.at(i)++;
			else break;
		}
	}
	sort(a.begin(), a.end(), greater<>());
	cout << a.at(0) << endl;
	return 0;
}
