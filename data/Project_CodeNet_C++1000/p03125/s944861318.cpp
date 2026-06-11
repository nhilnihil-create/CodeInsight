#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int x,y; cin >> x >> y;

	if (y % x == 0) {
		cout << x + y  << endl;
	}else {
		cout << y - x << endl;
	}

	return 0;
}
