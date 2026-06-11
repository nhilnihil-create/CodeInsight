#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){

	int X; cin >> X;

	int ans = 1;
	for(int i = 1; i <= X; i++){
		int tmp = i;
		for(int j = 2; j <= 100; j++){
			tmp *= i;
			if(tmp <= X){
				ans = max(ans, tmp);
			}
		}
		
	}

	cout << ans << endl;

}