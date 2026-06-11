#include "iostream"
#include "algorithm"
using namespace std;

int main()
{
	int n, *a,l;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cout << a[n - 1] << ' ';
	for (int i = 0; true; i++) {
		if (a[n - 1] / 2 < a[i]) {
			l = i;
			break;
		}
	}
	if (l == n - 1)cout << a[l - 1] << endl;
	else if (a[n - 1] / 2 - a[l - 1] < a[l] - a[n - 1] / 2)cout << a[l-1] << endl;
	else cout << a[l] << endl;
	return 0;
}