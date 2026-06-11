#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stdio.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i < (int)(b); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll mod = (ll)pow(10.0, 9.0) + 7;
pint dx[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

ll min(ll a, ll b)
{

	return (a < b) ? a : b;
}
string S;

ll N;
vector<ll> ans;
int main() {

	cin >> N;


	if (N == 3) {
		cout << 2 << " " << 5 << " " << 63;
		return 0;
	}
	
	for (int i = 1; i <= min(15000, 3 * (N / 3)); i++) {
		ans.push_back(2 * i);
	}

	if (N > 15000 && N % 2 == 0) {
		for (int i = 1; i <= N - 15000; i++) {
			ans.push_back(3 * (2 * i - 1));

		}
	}
	else if(N > 15000 && N % 2 == 1) {
		ans[ans.size() - 1] = 3;

		for (int i = 1; i <= N - 15000; i++) {
			ans.push_back(3 * (2 * i + 1));
		}
	}

	else {
		if (N % 3 == 0) {
			ans[ans.size() - 3] = 3;
			ans[ans.size() - 2] = 9;
		}

		else if (N % 3 == 1) {
			ans[ans.size() - 1] = 3;
			ans.push_back(9);

		}

		else if (N % 3 == 2) {
			ans.push_back(3);
			ans.push_back(9);
		}

	}

	for (auto &ct : ans) {

		cout << ct << " ";
	}

	return 0;
}
