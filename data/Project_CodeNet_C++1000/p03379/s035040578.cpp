#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0;i < n;i++) cin >> a[i], b[i] = a[i];
	sort(b, b + n);
	int ml = b[n / 2 - 1], mr = b[n / 2];
	for (int i = 0;i < n;i++) {
		if (a[i] <= ml) cout << mr << " ";
		else cout << ml << " ";
	}
	cout << endl;
}
