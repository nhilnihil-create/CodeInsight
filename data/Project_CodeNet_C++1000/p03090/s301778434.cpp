#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

int main()
{
	int n;
	cin >> n;
	if(n % 2){
		// 奇数だったら、N - iとの辺を繋がない。
		int m = (n-1) * n / 2; m -= (n - 1) / 2;
		cout << m << endl;
		for(int i = 0; i < n; i++){
			int a = i + 1;
			for(int j = a; j <= n; j++){
				if(a + j == n) continue;
				if(a == j) continue;
				cout << a << " " << j << endl;
			}
		}
	}
	else {
		int m = (n-1) * n / 2; m -= n / 2;
		cout << m << endl;
		for(int i = 0; i < n; i++){
			int a = i + 1;
			for(int j = a + 1; j <= n; j++){
				if(a + j == n + 1) continue;
				cout << a << " " << j << endl;
			}
		}
	}
}
