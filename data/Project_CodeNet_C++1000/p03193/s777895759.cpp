#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
#define mod(int)(1000000007)
using namespace std;
int test[213456];
int keta(int x) {
	int res = 0;
	while(x >= 1) {
		x /= 10; res++;
	}return res;
}
signed main() {
	int n, c, d, a, b, ans=0; cin >> n >> a >> b;
	for (int h = 0; h < n; h++) {
		cin >> c >> d;
		if (c >= a && d >= b) { ans++; }
	}
	cout << ans << endl;
	return 0;
}