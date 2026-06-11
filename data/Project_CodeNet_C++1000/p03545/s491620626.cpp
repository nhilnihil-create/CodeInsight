#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	string s;
	cin >> s;
	int x = (int)s.size();
	for (int i = 0;  i < pow(2,x - 1); ++i) {
		string ans = "";
		ans += s[0];
		int sum = s[0] - '0';
		for (int j = 0, p = 0; j < x - 1; ++j,p++) {
			if ((i >> j) & 1) {
			//	if (j == 0) {
				//	sum += (s[p] - '0') + (s[p + 1] - '0');
			//	}else {
					sum = (sum + (s[p + 1] - '0'));
			//	}
				//if (i == 0) {
				//	ans += ;
					ans += "+";
					ans += s[p+ 1];
			//	} 
			}else {
			//if (j == 0) {
				//	sum += (s[p] - '0') - (s[p + 1] - '0');
				//}else {
					sum = (sum - s[p + 1] + '0');
				//}
				//ans += s[p];
				ans += "-";
				ans += s[p + 1]; 
			//	cout << sum << " ";
			}
		//	cout << sum << " ";
		}
	//	cout << sum << " " << ans << endl;
		//cout << ans << endl;
		if (sum == 7) {
			cout << ans << "=7";
			return 0;
		}
	}
}


