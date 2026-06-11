#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;

int main() { 
	int n;
	cin >> n;
	map<int,bool> m;
	m[n] = 1;
	int cnt = 1;
	while (n > 0) {
		cnt++;
		if (n % 2 == 1) {
			n = (n * 3)  + 1;
		}else {
			n /= 2;
		}
		if (m[n]) {
			cout << cnt;
			return 0;
		}
	//	cout << n << endl;
		m[n] = 1;
	}
	return 0; 
} 

