#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N,C;
	cin>>N>>C;
	vector<vector<int>> D(C,vector<int>(C));
	rep(i,C) rep(j,C) cin>>D[i][j];
	vector<vector<int>> c(N,vector<int>(N));
	rep(i,N) rep(j,N) cin>>c[i][j];
	vector<map<int,int>> color(3);
	rep(i,N)
	{
		rep(j,N)
		{
			color[(i+j+2)%3][c[i][j]]++;
		}
	}
	ll ans=1e10;
	rep(i,C)
	{
		rep(j,C)
		{
			if(i==j) continue;
			rep(k,C)
			{
				if(i==k||j==k) continue;
				ll val=0;
				rep(cnt,3)
				{
					for(auto p : color[cnt])
					{
						if(cnt==0)
							val+=D[p.first-1][i]*p.second;
						else if(cnt==1)
							val+=D[p.first-1][j]*p.second;
						else
							val+=D[p.first-1][k]*p.second;
					}
				}
				ans=min(ans,val);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
