#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
typedef int64_t ll;

int N;

int main() {
	cin >> N;
	int ans = 0;
	rep(i, N) {
		int tmp;
		cin >> tmp;
		tmp--;
		ans += tmp;
	}
	cout << ans << endl;
}