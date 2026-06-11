#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
char c[55][55];
int n,m;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>c[i][j];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(c[i][j]=='.') continue;
			bool check=0;
			for(int k=0;k<4;k++){
				int nx=i+dx[k],ny=j+dy[k];
				if(0<=nx&&nx<n&&0<=ny&&ny<m){
					if(c[nx][ny]=='#') check=1;
				}
			}
			if(!check){
				cout<<"No";
				re 0;
			}
		}
	} 
	cout<<"Yes";
	re 0;
}