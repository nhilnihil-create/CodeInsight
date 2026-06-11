#include<bits/stdc++.h>
using namespace std;
using ll = long long;



int main()
{
	int n,c;
	cin >> n >> c;
	vector<vector<int>> D(c,vector<int>(c));
	for(int i = 0;i<c;i++)
	{
		for(int j = 0;j<c;j++)
		{
			cin >> D[i][j];
		}
	}

	vector<vector<int>> C(n,vector<int>(n));
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			cin >> C[i][j];
			C[i][j]--;
		}
	}
	vector<vector<int>> V(3);

	for(int i = 0;i<n;i++)
	{
		for(int j = 0 ;j<n;j++)
		{
			V[((i+1)+(j+1))%3].push_back(C[i][j]);
		}
	}
	 vector<vector<ll>> VV(3,vector<ll>(c,-1));
	ll ans = LLONG_MAX;
	for(int i = 0;i<c;i++)
	{
		for(int j = 0;j<c;j++)
		{
			if(i==j)continue;
			for(int k = 0;k<c;k++)
			{
				if(k==i||j==k)continue;
				ll now = 0;
				if(VV[0][i]==-1)
				{
					ll AA = 0;
					for(auto m:V[0])AA+=D[m][i];
					VV[0][i] =AA;
				}
				if(VV[1][j]==-1)
				{
					ll AA = 0;
					for(auto m:V[1])AA+=D[m][j];
					VV[1][j] =AA;
				}
				if(VV[2][k]==-1)
				{
					ll AA = 0;
					for(auto m:V[2])AA+=D[m][k];
					VV[2][k] =AA;
				}
				now += VV[0][i]+VV[1][j]+VV[2][k];
				ans = min(now,ans);
				
			}
		}
	}
	cout<<ans<<endl;
}