#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;
int main() {
	int a, b, cnt = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if (i % 10 == i / 10000 && (i / 10) % 10 == (i / 1000)%10)cnt++;
	}
	cout << cnt << endl;
	return 0;

}