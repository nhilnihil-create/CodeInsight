#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[3];
	for (auto& x : a) {
		cin >> x;
	}
	sort(rbegin(a), rend(a));
	int ans = 10 * a[0] + a[1] + a[2];
	cout << ans << endl;
}
