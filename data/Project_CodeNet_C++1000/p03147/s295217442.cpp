#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

//解説ac
int main()
{
	int n; cin >> n;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	int ans = 0;
	int active = 0;
	rep(i, n) {
		if (active < h[i]) {
			ans += h[i] - active;
			active = h[i];
		}
		else
			active = h[i];
	}
	cout << ans;

}
