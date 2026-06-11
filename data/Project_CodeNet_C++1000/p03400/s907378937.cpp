#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n, d, x; cin >> n >> d >> x;
	int cnt = 0;
	while (n--) {
		int a; cin >> a;
		int time = 1;
		while (time<=d) {
			cnt++;
			time += a;
		}
	}
	cout << cnt + x << endl;
    return 0;
}