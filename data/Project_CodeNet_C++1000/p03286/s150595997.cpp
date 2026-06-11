#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
  if (n == 0) { cout << 0 << endl; return 0; }

	string ans = "";
	while (n != 0) {
		int rem = n % -2;
		if (rem < 0) n -= 1;
		
		ans.push_back((rem ? '1' : '0'));
		n /= -2;
		
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}
