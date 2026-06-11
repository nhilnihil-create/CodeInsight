#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;

int main() {fio;
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[n - i - 1];
	} 
	if(a[0] != 2) {
		cout << -1 << endl;
		return 0;
	}
	ll L = 2, R = 3;
	for(int i = 1; i < n; i++) {
		if(L % a[i] != 0) L += (a[i] - L % a[i]);
		if(R % a[i] != 0) R -= R % a[i];
		if(L > R) {
			cout << -1 << endl;
			return 0;
		}
		R += a[i] - 1;
	}
	cout << L << ' ' << R << endl;
    return 0;
}