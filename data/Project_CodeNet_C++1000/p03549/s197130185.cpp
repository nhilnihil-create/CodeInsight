#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int ans = 100*(N-M) + 1900*M;
	rep(i,M) ans *= 2;
	cout << ans << endl;
	return 0;
}
