#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
	int a, b;
	cin >> a >> b;
	if ((a*b) % 2 == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	return 0;
}
