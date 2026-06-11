#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int l[1000006], r[1000006];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		scanf("%d %d", &l[i], &r[i]);
		r[i] = -r[i];
	}
	++ n;
	sort(l + 1, l + 1 + n);
	sort(r + 1, r + 1 + n);
	long long ans = 0, sl = 0, sr = 0;
	for (int i = 1; i <= n; ++ i){
		sl += l[n - i + 1];
		sr += r[n - i + 1];
		ans = max(ans, sl + sr);
	}
	cout << 2 * ans << endl;
}
