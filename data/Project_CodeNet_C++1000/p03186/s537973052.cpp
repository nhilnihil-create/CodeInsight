#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)



int main() {
	int a, b, c,ans;
	cin >> a >> b >> c;
	if (a + b < c) {
		ans = a+b+ + 1 + b;
		cout << ans << endl;
		return 0;
	}
	if (a + b >= c) {
		ans = b + c;
		cout << ans << endl;
		return 0;
	}

	return 0;
}