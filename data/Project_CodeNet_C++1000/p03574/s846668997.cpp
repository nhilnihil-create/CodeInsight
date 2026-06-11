/// Created by ...Lusifer
#include<bits/stdc++.h>
using namespace std;
 
#define pb 		push_back
#define mp 		make_pair
#define prior   priority_queue
#define MOD 	1000000007
#define INF64 	(long long)1e18
#define INF 	(int)1e9
#define PI 		3.1415926535897932384626433832795 
#define ll      long long
#define ld		long double
#define ret     return
#define NUM 	1000001
const int SIZE = 2e5+4;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
void fastio(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void solveTest(){
	int h,w;
	cin>>h>>w;
	string board[50];
	for(int i=0;i<h;i++) cin>>board[i];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(board[i][j]=='#') continue;
			int cnt=0;
			for(int d=0;d<8;d++){
				int ni = i+dy[d];
				int nj = j+dx[d];
				if(ni<0 || ni>=h) continue;
				if(nj<0 || nj>=w) continue;
				if(board[ni][nj]=='#') cnt++;
			}
			board[i][j] = char(cnt+'0');
		}
	}
	for(int i=0;i<h;i++){
		cout<<board[i]<<endl;
	}
	//cout<<endl<<"Time: "<<(float)clock()/CLOCKS_PER_SEC<<" seconds"<<endl;
	return ;
}
 
int main(){
	fastio();

	int t=1;
	//cin>>t;
	while(t--){
		solveTest();
 
	}
	return 0;
}