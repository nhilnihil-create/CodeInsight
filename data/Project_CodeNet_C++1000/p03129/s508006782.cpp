# include <bits/stdc++.h>
 
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	cout << ((n / 2 + n % 2 >= k) ? "YES":"NO");
}