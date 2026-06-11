#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	long long suma = 0, sumb = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		suma += a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		sumb += b[i];
	}

	long long addone = 0, addtwo = 0;
	for (int i = 0; i < n; i++)
	{
		if(a[i] >= b[i]) addone += a[i] - b[i];
		else addtwo += (b[i] - a[i] + 1) / 2;
	}

	if(addone <= sumb - suma && addtwo <= sumb - suma) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

