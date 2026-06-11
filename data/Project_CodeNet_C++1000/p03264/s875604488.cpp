#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<tuple>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	if (n % 2 != 0) {
		cout << (n / 2)*((n / 2) + 1) << endl;
	}
	else {
		cout << (n / 2)*(n / 2) << endl;
	}
	return 0;
}
