// B - Minesweeper
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int dy[]{-1, 1, 0, 0, -1, 1, -1, 1};
	int dx[]{ 0, 0,-1, 1, -1, 1,  1,-1};
	int H,W; cin>>H>>W;
	string S[H];
	rep(i, H) cin>>S[i];
	vvi A(H, vi(W, -1));
	rep(h, H)
		rep(w, W){
			if(S[h][w] == '#') continue;
			A[h][w] = 0;
			rep(k, 8){
				int y = h + dy[k], x = w + dx[k];
				if(y<0 || H<=y || x<0 || W<=x) continue;
				if(S[y][x] == '#') A[h][w]++;
			}
		}
	rep(h, H){
		rep(w, W)
			if(A[h][w] < 0) cout<<"#"; else cout<<A[h][w];
		puts("");
	}
}
