// B - Minesweeper
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int dy[]{-1, 1, 0, 0, -1, 1, -1, 1};
	int dx[]{ 0, 0,-1, 1, -1, 1,  1,-1};
	int H,W; cin>>H>>W;
	string S[H]; rep(i, H) cin>>S[i];
	rep(h, H)
		rep(w, W){
			if(S[h][w] == '#') continue;
			int c = 0;
			rep(k, 8){
				int y = h + dy[k], x = w + dx[k];
				if(y<0 || H<=y || x<0 || W<=x) continue;
				if(S[y][x] == '#') c++;
			}
			S[h][w] = c + '0';
		}
	rep(h, H) cout<<S[h]<<endl;
}
