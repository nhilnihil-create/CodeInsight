#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<iomanip>

using namespace std;

int main(void) {
	long long n, p;
	cin >> n >> p;
	long long ans;
	if (n == 1) {
		cout << p;
	}
	else {
		for (long long i = 1; i <= p && pow(i, n) <= p; i++) {
			if (p % ((long long)pow(i, n)) == 0) {
				ans = i;
			}
			//cout << i << endl;
		}
		cout << ans;
	}
	
	return 0;
}