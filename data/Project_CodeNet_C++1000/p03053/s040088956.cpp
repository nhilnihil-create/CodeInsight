#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int(i)=int (a);i<=int (b);i++)
#define ff(i,a,b) for(int (i)=int (a);i<int(b);i++)
#define F(i,a,b) for(int (i)=int(a);i>=int (b);i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define vt vector
#define ll long long
#define ld long double
#define all(x) x.begin(),x.end()
#define lower(p,x) lower_bound(all(p),x)
#define upper(p,x) upper_bound(all(p),x)
#define ms(a,x) memset(a,x,sizeof a)
typedef pair<int,int> ii;
const double pi=acos(-1.0);
const double eps=1e-5;
const int N=1e6+6,mod=1e9+7,INF=1<<30;
char s[1002][1002];
int d[1002][1002];
int n,m,k;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool pd(int x,int y){
	if(x>0&&x<=n&&y>0&&y<=m&&s[x][y]!='#') return 1;
	return 0;
}
void solve()
{
	int ans=0;
	cin>>n>>m;
	queue<ii> qu;
	ms(d,-1);
	f(i,1,n){
		f(j,1,m){
			cin>>s[i][j];
			if(s[i][j]=='#'){
				qu.push(ii(i,j));
				d[i][j]=0;
			}
		}
	}
	while(!qu.empty()){
		int x=qu.front().fi,y=qu.front().se;
		qu.pop();
		ff(i,0,4){
			int nx=x+dx[i],ny=y+dy[i];
			if(!pd(nx,ny)) continue;
			if(d[nx][ny]==-1){
				d[nx][ny]=d[x][y]+1;
				ans=max(ans,d[nx][ny]);
				qu.push(ii(nx,ny));
			}
		}
	}
	cout<<ans;

}int main(){
	solve();
	return 0;
}










