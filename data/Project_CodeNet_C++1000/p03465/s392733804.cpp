#include <bits/stdc++.h>
using namespace std;

bitset<4000005> f;
int n, s, a[2005];

int main() {
	cin >> n;
	f.set(0);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		f |= (f << a[i]);
		s += a[i];
	}
	for(int i = (s+1)/2; i <= s; i++){
		if(f[i]){
			cout << i << endl;
			break;
		}
	}

	return 0;
}