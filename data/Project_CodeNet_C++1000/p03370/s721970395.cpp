#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n, x;
	cin >> n >> x;
	int mind = __INT_MAX__;
	int total = 0;

	rep(i, n){
		int a;
		cin >> a;
		total += a;
		mind = min(mind, a);
	}

	cout << (x-total)/mind + n << endl;

}