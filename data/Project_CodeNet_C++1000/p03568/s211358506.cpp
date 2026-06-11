#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n], even = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] % 2 == 0) even++;
	}

	long long fodd = pow(2, even);
	cout << pow(3, n) - fodd << endl;
	return 0;
}
