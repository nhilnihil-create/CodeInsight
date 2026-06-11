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
char c[50][50];
int cnt[50][50];
int n,m;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>c[i][j];
			if(c[i][j]=='#'){
				for(int dx=-1;dx<=1;dx++){
					for(int dy=-1;dy<=1;dy++){
						if(!dx&&!dy) continue;
						int nx=i+dx,ny=j+dy;
						if(0<=nx&&nx<n&&0<=ny&&ny<m) cnt[nx][ny]++;
					}
				} 
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			if(c[i][j]=='.') cout<<cnt[i][j];
			else cout<<'#';
		cout<<"\n";
	}
		
	re 0;
}