#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string b; cin >> b;
	string  ans;
	if (b == "A") ans = "T";
	if (b == "T") ans = "A";
	if (b == "C") ans = "G";
	if (b == "G") ans = "C";	
	cout << ans << endl;
	return 0;
}