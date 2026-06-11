#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	string ans = "";
	while (n) {
		if (n % 2) {
			n--;
			ans += "1";
		}else {
			ans += "0";
		}
		n /= -2;
	}	
	reverse(ans.begin(),ans.end());
	if (ans == "")  ans = "0";
	cout << ans;
}

