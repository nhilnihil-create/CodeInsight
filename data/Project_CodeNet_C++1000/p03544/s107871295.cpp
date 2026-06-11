#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
	int N;
	cin >> N;
	vector<ll> v(N + 1);
	if (N == 0){
		cout << 2 << endl;
		return 0;
	}
	if (N == 1){
		cout << 1 << endl;
		return 0;
	}
	v[0] = 2LL;
	v[1] = 1LL;
	for (int i = 2; i <= N; i++){
		v[i] = v[i - 1] + v[i - 2];
	}
	cout << v[N] << endl;
	return 0;
}
