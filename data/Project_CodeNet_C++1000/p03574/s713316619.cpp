// B - Minesweeper
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
#define all(x) (x).begin(),(x).end()
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define irp(i,s,e) for(int i=(int)(s);i>(int)(e);--i)

int main(){
	int dy[]{-1, 1, 0, 0, -1, 1, -1, 1};
	int dx[]{ 0, 0,-1, 1, -1, 1,  1,-1};
	int H,W; cin>>H>>W;
	string S[H];
	rp(i,0,H) cin>>S[i];
	vvi A(H, vi(W, -1));
	rp(h,0,H){
		rp(w,0,W){
			if(S[h][w] == '#') continue;
			A[h][w] = 0;
			rp(k,0,8){
				int y = h + dy[k], x = w + dx[k];
				if(y<0 || H<=y || x<0 || W<=x) continue;
				if(S[y][x] == '#') A[h][w]++;
			}
		}
	}

	// rp(h,0,H){
	// 	rp(w,0,W){
	// 		cout<<setw(3)<<A[h][w]<<" ";
	// 	}
	// 	puts("");
	// }
	// puts("");


	rp(h,0,H){
		rp(w,0,W){
			if(A[h][w] < 0) cout<<"#";
			else cout<<A[h][w];
		}
		puts("");
	}

}
