#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,d,e,k;
	cin >> a >> b >> c >> d >> e >> k;
	string ans;
	if (e - a <= k){
		ans = "Yay!";
	}
	else{
		ans = ":(";
	}
	cout << ans << endl;
}
