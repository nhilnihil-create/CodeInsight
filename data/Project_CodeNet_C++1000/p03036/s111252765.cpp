#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll r, d, a;
	cin >> r >> d >> a;
	ll temp = (r * a) - d;
	for(int i = 1; i <= 10; i++) {
		cout << temp << "\n";
		a = temp;
		temp = (r * a) - d;
	}
}
