#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn], ind;
double mn = 1000000007.0;
int main() {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int x = a[n - 1];
	double d = x / 2.0;
//	cout << d << endl;
	for(int i = 0; i < n - 1; i++) {
		if(abs(a[i] - d) < mn) {
			mn = abs(a[i] - d);
			ind = i;
		}
	}
	cout << x << " " << a[ind];
	return 0;
}