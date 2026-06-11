#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		int num = i, sum = 0;
		while(num > 0){
			sum += num % 10;
			num /= 10;
		}
		if(a <= sum && sum <= b) ans += i;
	}
	cout << ans << endl;
	return 0;
}