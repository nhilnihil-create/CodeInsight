#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int r, d, x;; cin >> r >> d >> x;

	int x_next;
	int x_now = x;
	for (int  i = 1; i <= 10; i++) {
		x_next = r * x_now - d;
		cout << x_next << endl;
		x_now = x_next;
	}
	
	return 0;
}