#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	bool ok = 1;
	int H,W,N,x,y;
	string A,B;
	cin >> H >> W >> N;
	cin >> x >> y;
	cin >> A;
	cin >> B;
	x--;y--;
	//まずは横方向に出す事を考える
	//left,right
	int left = 0,right = W; //[left,r-1]の範囲にyが存在すると横方向生存
	for(int i=N-1;i>=0;i--){
		if(B[i]=='L')right = min(right+1,W);
		else if(B[i]=='R') left = max(0,left-1);
		
		if(A[i]=='L')left = left + 1;
		else if(A[i]=='R') right = right - 1;
		
		if(left>=right)ok = 0;
	}
	if(y<left || y>=right)ok = 0;
	//up,down
	left = 0,right = H;
	//xを反転させる まず右端までの距離を出す 
	x = H-1-x;
	for(int i=N-1;i>=0;i--){
		if(B[i]=='D')right = min(right+1,H);
		else if(B[i]=='U')left = max(left-1,0);
		if(A[i]=='D')left++;
		else if(A[i]=='U')right--;
		if(left>=right)ok = 0;
	}
	if(x<left || x>=right)ok = 0;
	if(ok)cout << "YES" << endl;
	else cout << "NO" << endl;
	
}
