#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<typeinfo>
#include<complex>
using namespace std;
using ll = long long int;
const int mod = 1e9 + 7;
#define rep(i, a, b) for(ll i = a;i < b; i++)
const long double PI = (acos(-1));

int main() {

	string s;
	cin >> s;

	int n = s.size(), mini = 1000;
	rep(i, 0, n - 2) {
		int ans = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
		mini = min(mini, abs(ans - 753));
	}

	cout << mini << endl;

	return 0;
}