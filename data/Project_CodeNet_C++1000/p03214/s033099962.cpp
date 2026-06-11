#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fast ios::sync_with_stdio(false), cout.tie(), cin.tie();
#define sz(s) int(s.size())

int main(){
	int n;
	cin >> n;
	ld a[n], sum = 0, min = 101, x = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sum /= n;
	for (int i = 0; i < n; i++){
		if (abs(a[i] - sum) < min){
			min = abs(a[i] - sum);
			x = i;
		}
	}
	cout << x;
}
