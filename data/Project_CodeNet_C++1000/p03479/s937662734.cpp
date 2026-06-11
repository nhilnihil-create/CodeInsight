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
int main(){
	long long int x, y,ans=1;
	cin >> x >> y;
	while (2 * x <= y) {
		ans++;
		x = 2 * x;
	}
	cout << ans << endl;
	return 0;
}