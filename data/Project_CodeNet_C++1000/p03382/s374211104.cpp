#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 13;
int n, mx, num, a[maxN], mn = 1e9 + 13, val;;
int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
	if (a[i] > mx) {
	    mx = a[i];
	    val = i;
	}
    }
    for (int i = 0; i < n; i++) {
	if (i != val) {
	if (abs(a[i] - mx / 2) < mn) {
	    mn = abs(a[i] - mx / 2);
	    num = a[i];
	}
	}
    }
    cout << mx << " " << num << endl;
}
