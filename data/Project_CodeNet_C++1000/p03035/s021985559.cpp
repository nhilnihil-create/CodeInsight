#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	int a, b;
	cin >> a >> b;
	if (a >= 13) {
		b = b;
	}
	else if (a >= 6) {
		b /= 2;
	}
	else {
		b = 0;
	}
	cout << b;
	return 0;
}

