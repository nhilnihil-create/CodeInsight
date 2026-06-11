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
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	int n,ans=1;
	int mi = 1;
	int e = 0, o = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
		ans *= 3;
	}
	for (int i = 0; i < n; i++) {
		if (a.at(i) % 2 == 0)e++;
		else o++;
	}
	for(int i=0;i<e;i++){
		mi *= 2;
	}
	cout << ans - mi << endl;
		return 0;
	}
