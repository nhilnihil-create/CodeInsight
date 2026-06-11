#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int H,W;
  	cin>>H>>W;
  
  	string grid[H];
  	rep(i,H) cin>>grid[i];
  	const int dx[8]={-1,-1,-1,0,0,1,1,1};
  	const int dy[8]={-1,0,1,1,-1,-1,0,1};
  	
  	
  	rep(i,H){
     	rep(j,W){
          	int count=0;
         	if(grid[i][j]=='.'){
            	rep(d,8){
                	int ni=i+dy[d];
                  	int nj=j+dx[d];
                  	if(ni<0||H<=ni) continue;
                  	if(nj<0||W<=nj) continue;
                  	if(grid[ni][nj]=='#') count++;
                }	
              	grid[i][j]=char(count+'0');
            }
        }
    }
  
  	rep(i,H) cout<<grid[i]<<endl;
  
  	
  	
}