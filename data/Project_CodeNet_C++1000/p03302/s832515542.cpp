#include <bits/stdc++.h>
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
 
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	if (a + b == 15) {
	    cout << "+";
	} else if (a * b == 15) {
	    cout << "*";
	} else cout << 'x';
	return 0;
}  