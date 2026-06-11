#include<bits/stdc++.h>

using namespace std;
int a[110000];
int main() {
	int n;
	cin >> n;
	for(int i = 0;i < n; i ++){
		cin >> a[i];
	}
	int gcd = a[0];
	for(int i = 1;i < n; i++){
		gcd = __gcd(gcd, a[i]);
		if(gcd == 1) break; // once 1 occurs, the answer must be 1
	}
	cout << gcd << endl;
	return 0;
}