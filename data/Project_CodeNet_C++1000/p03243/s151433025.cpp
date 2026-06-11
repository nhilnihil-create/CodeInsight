#include <bits/stdc++.h>
using namespace std;

int main() {
	int	n;
	int ans;

	cin >> n ;
	if(n>888) ans=999;
	else if(n>777) ans=888;
	else if(n>666) ans=777;
	else if(n>555) ans=666;
	else if(n>444) ans=555;
	else if(n>333) ans=444;
	else if(n>222) ans=333;
	else if(n>111) ans=222;
	else ans=111;
	cout << ans << endl;
	return 0;
}