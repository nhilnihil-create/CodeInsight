#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)
typedef long long ll;

int main(){
	vector<int> N(3);
	rep(i, 3) cin >> N.at(i);
	sort(N.begin(), N.end());

	int ans = 0;
	ans = N.at(2) - N.at(1) + (N.at(1) - N.at(0)) / 2;
	if ((N.at(1) - N.at(0)) % 2) ans += 2;
	cout << ans << endl;
}