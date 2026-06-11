#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
static long long INF = (1LL<<62);

int N, C;
vector<vector<int>> D;
vector<vector<int>> GC0, GC1;

int DF[4][31] = {0};
void calcDF(){
	for(int r=0; r<3; r++){
		for(int c=0; c<C; c++){
			int w = 0;
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					if((i+j)%3 != r) continue;
					w += D[GC0[i][j]][c];
				}
			}
			DF[r][c] = w;
		}
	}
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> C;
	D.assign(C, vector<int>(C, 0));
	GC0.assign(N, vector<int>(N, 0));
	GC1.assign(N, vector<int>(N, 0));
	for(int i=0; i<C; i++){
		for(int j=0; j<C; j++){
			int d; cin >> d;
			D[i][j] = d;
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int c; cin >> c; c--;
			GC0[i][j] = c;
		}
	}

	calcDF();
	LL ans = INF;
	for(int i=0; i<C; i++){
		for(int j=0; j<C; j++){
			if(j == i) continue;
			for(int k=0; k<C; k++){
				if(k==i || k==j) continue;
				LL w = DF[0][i]+DF[1][j]+DF[2][k];
				if(ans > w){
					ans = w;
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}