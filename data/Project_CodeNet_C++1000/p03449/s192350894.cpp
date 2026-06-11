#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
const int MAX = 1e2;
int a[MAX] , b[MAX] , n , mx = 0 , k;
int main() {
    cin >> n;
	for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		k += b[i];
	}
	k += a[0];
	mx = k;
	for (int i = 1; i < n; ++i) {
		k += a[i] - b[i - 1];
		if (k > mx) mx = k;
	}
	cout << mx << endl;
}