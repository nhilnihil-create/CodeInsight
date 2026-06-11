#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
using ll = long long;



int main() {
	int a, b,ans;
	cin >> a >> b;
	ans = max(a+b,a-b);
	ans = max(ans, a * b);
	cout << ans << endl;

	return 0;
}