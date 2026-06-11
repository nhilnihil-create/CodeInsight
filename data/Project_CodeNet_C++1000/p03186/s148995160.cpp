#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

int main() {
	int a, b, c; cin >> a >> b >> c;
	if(a+b >= c-1){
		cout << b + c;
		return 0;
	}else{
		cout << a + b + b + 1;
	}
	return 0;
}
