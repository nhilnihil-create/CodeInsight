#include<bits/stdc++.h>
using namespace std;
int h,w;
int arr[55][55];
int ret[55][55];
int dx[8]={-1,0,1,-1,1,-1,0,1};
int dy[8]={1,1,1,0,0,-1,-1,-1};
void f(int y,int x){
	int &r = ret[y][x];
	r = 0;
	for(int i=0; i<8; i++){
		int yy = y+dy[i];
		int xx = x+dx[i];
		r+=arr[yy][xx];
	}
}
int main(){
	memset(ret,-1,sizeof(ret));
	cin>>h>>w;
	for(int i=1; i<=h; i++){
		string s;
		cin>>s;
		for(int j=0; s[j]; j++){
			if(s[j]=='#') arr[i][j+1] = 1;
		}
	}
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			if(arr[i][j]==0) f(i,j);
		}
	}
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			if(ret[i][j]==-1) cout<<'#';
			else cout<<ret[i][j];
		}
		cout<<'\n';
	}
}