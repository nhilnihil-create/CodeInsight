#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include <stdio.h>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main() {
	int a[5];
	int ans = 0;
	int mini = INF;
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		if (a[i] % 10 != 0) {
			ans += ((a[i] / 10) + 1) * 10;
		}
		else ans += a[i];

		if (a[i] % 10 < mini&&a[i]%10!=0)mini = a[i] % 10;
	}
	if (mini == INF)cout << ans << endl;
	else
	{
		cout << ans - (10-mini) << endl;
	}
	
	return 0;
}