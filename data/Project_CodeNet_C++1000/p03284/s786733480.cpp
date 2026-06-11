#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int N, K;
	cin >> N >> K;
	int ans = 1;
	if (N%K == 0){
		ans = 0;
	}
	cout << ans << endl;
	return 0;
}
