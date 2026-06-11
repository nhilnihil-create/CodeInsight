#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

const ll mod = 1e9+7;

// void chmod(ll &M){
//     if(M >= mod) M %= mod;
//     else if(M < 0){
//         M += (abs(M)/mod + 1)*mod;
//         M %= mod;
//     }
// }



int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	char fi[n][n];

	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> fi[i][j];
	int ans = 0;

	for(int b=0; b<n; ++b){
		bool flg = true;
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				if(fi[i][(j+b)%n] != fi[j][(i+b)%n]) flg = false;
				// if(b == 1){
				// 	printf("(i, j) = %c\n", fi[i][(j+b)%n]);
				// 	printf("(j, i) = %c\n", fi[j][(i+b)%n]);
				// }
			}
		}
		if(flg) ans += n;
	}

	cout << ans << endl;
	return 0;
}