#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 303;
int f[maxn][maxn][maxn] , l , k;
char s[maxn];
int main(){
	cin >> s + 1 >> k;
	l = strlen(s + 1);
	int ans = 1;
	for(int c = 0 ; c <= k ; ++ c){
		for(int i = 1 ; i < l ; ++ i){
			for(int j = l ; j > i ; -- j){
				if(s[i] == s[j])
					f[i][j][c] = max(f[i][j][c] , f[i - 1][j + 1][c] + 1);
				else if(c > 0)
					f[i][j][c] = max(f[i][j][c] , f[i - 1][j + 1][c - 1] + 1);
				f[i][j][c] = max(f[i][j][c] , f[i - 1][j][c]);
				f[i][j][c] = max(f[i][j][c] , f[i][j + 1][c]);
				f[i][j][c] = max(f[i][j][c - 1] , f[i][j][c]);
			}
			ans = max(ans , f[i][i + 1][c] * 2);
			if(i < l - 1)
				ans = max(ans , f[i][i + 2][c] * 2 + 1);
		}
	}
	cout << ans << endl;
	return 0;
}