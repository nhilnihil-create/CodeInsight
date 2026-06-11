#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,K;
	cin >> N >> K;
	
	string a;
	cin >> a;
	
	a[K-1] = (char)(((int)a[K-1])+32);
	cout << a;
	
	return 0;
}
