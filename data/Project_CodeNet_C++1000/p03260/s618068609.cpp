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
	int a, b;
	cin >> a >> b;
	if (a % 2 != 0 && b % 2 != 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}