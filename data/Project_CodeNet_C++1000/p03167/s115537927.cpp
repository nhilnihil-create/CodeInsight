#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

ll pow(ll a, ll b, ll m)
{
    ll  ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

bool vis[1001][1001];
char a[1001][1001];
ll b[1001][1001];
int h,w;

int dfs(int r,int c){
    
    if(a[r][c]=='#')
       return 0;
    if(r==0&&c==0){ vis[0][0]=true; return 1;}
    if(b[r][c]>0||vis[r][c]) return b[r][c];
    vis[r][c]=true;
    if(r-1>=0)
      b[r][c]+=dfs(r-1,c);
    if(c-1>=0) b[r][c]+=dfs(r,c-1);
    b[r][c]=b[r][c]%MOD;
    return b[r][c];
}


int main()
{
	IOS;
	int t=1; //cin>>t;
	while(t--){
	  cin>>h>>w;
	  for(int i=0;i<h;i++){
	      for(int j=0;j<w;j++){ cin>>a[i][j]; b[i][j]=0; vis[i][j]=false;}
	  }
	  dfs(h-1,w-1);
	  cout<<b[h-1][w-1];
	  cout<<"\n";
	}    

}