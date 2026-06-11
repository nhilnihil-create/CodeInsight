#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
	int n;
	cin >> n;
	string s = "";
	while (n) {
		int num = 0;
		num = n % 2;
		if (num < 0) {
			num += 2;
		}
		s += char(num + '0');
		n = (n - num) / (-2);
	}
	reverse(s.begin(), s.end());
	if (s == "") cout << 0 << endl;
	else cout << s << endl;
	return 0;
}
