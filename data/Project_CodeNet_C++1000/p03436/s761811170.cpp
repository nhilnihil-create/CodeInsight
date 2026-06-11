#define _USE_MATH_DEFINES //M_PI, M_E
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
ll power(ll a,ll b){ll r=1;for(;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int h,w;
	cin>>h>>w;
	char ch[h][w];
	int white = 0;
	for(int i = 0; i<h; i++) for(int j = 0; j<w; j++){cin>>ch[i][j] ; white += ch[i][j]=='.';}
	queue<ar<int,3>> q;
	q.push({0,0,1});
	bool vis[h][w];
	memset(vis,0,sizeof(vis));
	vis[0][0] = 1;
	vector<ar<int,2>> v = {{-1,0},{1,0},{0,1},{0,-1}};
	int ans = 0;
	while(!q.empty())
	{
		auto y = q.front();
		q.pop();
		if(y[0]==h-1 && y[1]==w-1){ ans = y[2]; break;}
		for(auto it:v)
		{
			int y2 = it[0]+y[0], x = it[1]+y[1];
			if(y2>=0 && y2<h && x>=0 && x<w && ch[y2][x] =='.' && !vis[y2][x])
			{
				vis[y2][x] = 1;
				q.push({y2,x,y[2]+1});
			}
		}
	}
	if(!vis[h-1][w-1]) cout<<-1<<endl;
	else 
	cout<<(white-ans)<<endl;
	return 0;
}