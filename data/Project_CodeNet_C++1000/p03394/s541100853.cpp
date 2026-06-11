
#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for (int i = a; i < b; i++)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n; cin >> n;
	if (n == 3) cout << "2 5 63" << endl;
	else {
		int a[8];
		if (n&1) {
			int b[] = {6,3,9,2,10,4,8,12};
			f(i,0,8) a[i] = b[i];
		} else {
			int b[] = {2,10,3,9,4,8,6,12};
			f(i,0,8) a[i] = b[i];
		}
		f(i,0,n) cout << a[i%8]+12*(i/8) << " ";
		cout << endl;
	}

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

