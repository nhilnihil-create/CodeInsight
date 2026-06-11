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
	if (n < 1200) {
		cout << "ABC" << endl;
	}
	else if (1200 <= n && n < 2800) {
		cout << "ARC" << endl;
	}
	else {
		cout << "AGC" << endl;
	}
	return 0;
}
