#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int chk = n / 111;
	if (n % 111) ++chk;
	cout << (chk * 111) << '\n';
	return 0;
}