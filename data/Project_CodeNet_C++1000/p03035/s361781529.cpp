#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;
#define ll long long
#define ar array

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	 int A,B;
	 cin >> A >> B;

	 if (A>=13) {
		 cout << B << endl;
	 } else if (A>=6 && A<=12) {
		 cout << B/2 << endl;
	 } else {
		 cout << 0 << endl;
	 } 
	 return 0;
}
