#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	string s;
	cin >> s;
	int N;
	cin >> N;
	map<string, int> mp;
	for (int i = 0; i < s.length(); ++i) {
		for (int j = 0; j <= min((int)s.length(), N + 2); ++j) {
			string _s = s.substr(i, j);
			mp[_s]++;
		}
	}

	auto x = mp.begin();
	for (int i = 0; i < N; ++i) {
		++x;
	}
	cout << x->first << endl;


	return 0;
}