#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 5003
#define ll long long

using namespace std;

int n, m, a, b;
int pos[N];
ll f[N][N << 1];

int main(){
	cin >> n >> a >> b; m = n * 2 + 1;
	for(int i = 1; i <= n; ++i){
		int x; scanf("%d", &x);
		pos[x] = i * 2;
	}
	memset(f, 127, sizeof f);
	for(int j = 1; j <= m; ++j) f[0][j] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			ll tmp = (j != pos[i]) * (j < pos[i] ? b : a);
			tmp += f[i - 1][j - !(j & 1)]; 
			f[i][j] = min(f[i][j - 1], tmp);
		}
	cout << f[n][m] << endl;
	return 0;
}