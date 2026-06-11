#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100011, inf = 1000111222;



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a[4];
    for (int i = 0; i < 4; ++i) cin >> a[i];
    sort(a, a + 4);
	if (a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}
