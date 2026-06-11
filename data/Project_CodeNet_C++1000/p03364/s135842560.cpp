#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
const int MAXN = 605;

int n;
char str[MAXN][MAXN];
int ps[MAXN][MAXN];

int gs(int sx, int ex, int sy, int ey){
	int ret = ps[ex][ey];
	if(sx>0) ret -= ps[sx-1][ey];
	if(sy>0) ret -= ps[ex][sy-1];
	if(sx>0&&sy>0) ret += ps[sx-1][sy-1];
	return ret;
}

int Do(){
	int ret = 0;
	for(int i=1; i<n; i++){
		memset(ps, 0, sizeof(ps));
		for(int j=0; j<2*n-i; j++){
			for(int k=0; k<2*n-i; k++){
				char p = str[j][k+i];
				char q = str[k][j+i];
				if(p == q){
					ps[j][k]++;
				}
			}
		}
		for(int j=0; j<2*n-i; j++){
			for(int k=0; k<2*n-i; k++){
				if(j) ps[j][k] += ps[j-1][k];
				if(k) ps[j][k] += ps[j][k-1];
				if(j && k) ps[j][k] -= ps[j-1][k-1];
			}
		}
		for(int j=0; j<n-i; j++){
			ret += (gs(j, j+n-1, j, j+n-1) == n*n);
		}
	}
	return ret;
}

int trial(int x, int y){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			char c = str[x+i][y+j];
			char d = str[x+j][y+i];
			if(c != d) return 0;
		}
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%s", str[i]);
	}
	for(int i=0; i<2*n; i++){
		for(int j=0; j<2*n; j++){
			str[i][j] = str[i%n][j%n];
		}
	}
	int ret = 0;
	for(int i=0; i<n; i++){
		ret += trial(i, i);
	}
	ret += Do();
	for(int i=0; i<n+n; i++){
		for(int j=0; j<i; j++){
			swap(str[i][j], str[j][i]);
		}
	}
	ret += Do();
	cout << ret << endl;
}
