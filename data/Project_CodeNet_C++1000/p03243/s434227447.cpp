#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >>n;
	const  int p = 111;
	int tmp;
	for (int i = 1; i <= 9; i++) {
		if ( n <= i * p) {
			tmp = i;
			break;
		}
	}
	cout << tmp * p << endl;
	return 0;
}