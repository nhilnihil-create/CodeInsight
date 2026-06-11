#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H,W,N;
	cin >> H >> W >> N;
	int x,y;
	cin >> x >> y;
	x--;y--;
	string S;
	cin >> S;
	string T;
	cin >> T;
	bool alive = 1;
	string a = "LURD";
	string b = "RDLU";
	int dx[4] = {0,-1,0,1};
	int dy[4] = {-1,0,1,0};
	rep(j,4){
		int curx = x;
		int cury = y;
		rep(i,N){
			//a君はできるだけj方向に進み外に出す
			//b君はできるだけjとは逆方向に進むがマス目からは出ないようにする
			if(S[i]==a[j]){
				curx += dx[j];
				cury += dy[j];
			}
			if(curx<0||cury<0||curx>=H||cury>=W)alive = 0;
			if(T[i]==b[j]){
				int nx = curx+dx[(j+2)%4];
				int ny = cury+dy[(j+2)%4];
				if(nx>=0&&nx<H)curx = nx;
				if(ny>=0&&ny<W)cury = ny;
			}
		}
	}
	if(alive)cout << "YES" << endl;
	else cout << "NO" << endl;
}