#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
using namespace std;

int main() {
	map<long long int, long long int>mp;
	//cout << fixed << setprecision(10);
	long long int n,m,a,b, k, sum = 0, d, w, h;
	long long dp[200005] = {}, memo[200005] = {};
	string str,str2;
	cin >> a>>b>>k;
	for (int i = 0; i < k; i++) {
		if (i % 2 == 0) {
			a = a / 2;
			b += a;
		}
		else {
			b /= 2;
			a += b;
		}
	}
	cout << a << " " << b;
}
