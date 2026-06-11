//Pantyhose(black) + glasses = infinity

#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " = " << x << '\n';
#define BP() cerr << "OK!\n";
#define PR(A, n) {cerr << #A << " = "; for (int _=1; _<=n; ++_) cerr << A[_] << ' '; cerr << '\n';}
#define PR0(A, n) {cerr << #A << " = "; for (int _=0; _<n; ++_) cerr << A[_] << ' '; cerr << '\n';}
#define FILE_NAME "data"

int main() {
	#ifdef GLASSES_GIRL
		freopen(FILE_NAME".in", "r", stdin);
		freopen(FILE_NAME".out", "w", stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	if (a+b>c && b+c>a && c+a>b && a==b && b==c)
		cout << "Yes";
	else
		cout << "No";
}