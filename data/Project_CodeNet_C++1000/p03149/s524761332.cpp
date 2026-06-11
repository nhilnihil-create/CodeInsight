#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	vector<int> N(4);
	cin >> N[0] >> N[1] >> N[2] >> N[3];
	sort(N.begin(), N.end());
	if (N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9)cout << "YES" << endl;
	else cout << "NO" << endl;
}