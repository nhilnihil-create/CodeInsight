#include<iostream>
#include<algorithm>
#include<iomanip>
using lint=int64_t;
using namespace std;

int main()
{
	const int dv[]={1,0,-1};
	
	int N;
	int t[110]={};
	int v[110]={};

	cin >> N;
	for(int i=0;i<N;i++)
		cin >> t[i];
	for(int i=1;i<N;i++)
		t[i]+=t[i-1];
	for(int i=0;i<N;i++)
		t[i]*=2;
	for(int i=0;i<N;i++)
	{
		cin >> v[i];
		v[i]*=2;
	}

	int dp[50010][210]={};
	dp[0][0]=1;
	dp[t[N-1]][0]=1;
	int index=0;
	for(int i=0;i<t[N-1];i++)
	{
		for(int j=0;j<=v[index];j++)
		{
			if(dp[i][j]==1)
			{
				for(int k=0;k<3;k++)
				{	
					int nv=j+dv[k];
					if(i+1==t[index])
					{
						if(0<=nv && nv<=min(v[index],v[index+1]))
							dp[i+1][nv]=1;
					}
					else
					{
						if(0<=nv && nv<=v[index])
							dp[i+1][nv]=1;
					}
				}
			}
		}
		if(i+1==t[index])
			index++;
	}

	int mv[50010]={};
	mv[t[N-1]]=0;
	for(int i=t[N-1]-1;i>=0;i--)
	{
		for(int j=0;j<3;j++)
		{
			int pv=mv[i+1]-dv[j];
			if(0<=pv && dp[i][pv]==1)
				mv[i]=max(mv[i],pv);
		}
	}

	double ans=0;
	for(int i=0;i<t[N-1];i++)
	{
		ans+=abs(mv[i+1]-mv[i])/2.0;
		ans+=min(mv[i+1],mv[i]);
	}

	cout << fixed << setprecision(5);
	cout << ans/4.0 << endl;
	return 0;
}
