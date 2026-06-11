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
	int n, k;
	cin >> n >> k;
	if (n%k == 0) {
		cout << "0" << endl;
	}
	else {
		cout << "1" << endl;
	}
	return 0;
}