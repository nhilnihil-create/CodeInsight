#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int main() {
    int r,g,b,n;
	cin >> r >> g >> b >> n;

	int cnt = 0; 
	rep(i, (n / r) + 1){
		rep(j, (n / g) + 1){
			if(((n - (i * r + j * g)) % b == 0) && n >= (i * r + j * g)){
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}
