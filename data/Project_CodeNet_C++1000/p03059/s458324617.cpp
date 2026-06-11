#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define PI 3.141592653589793

using namespace std;
using ll = unsigned long long;

int main() {

	int a, b, t;

	cin >> a >> b >> t;

	int ans = 0;
	int aa = 1;
	while (t + 0.5 > a*aa) {

		aa++;
		ans += b;
	}
	
	cout << ans << endl;

	return 0;
}