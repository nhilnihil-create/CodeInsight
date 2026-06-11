		#include<bits/stdc++.h>

		using namespace std;

		int main()
		{ios_base::sync_with_stdio(false);
		    cin.tie(NULL);
		    int n,m;
		    long long int ma=-1;
		    cin>>n>>m;
		    long long int a[n+1][3];
		    for(int i=1;i<=n;i++)
		    {
		    	for(int j=0;j<3;j++)
		    	{
		    		cin>>a[i][j];
		    	}	
		    }
		    for(int j=0;j<8;j++)
		    {
		    	vector<long long int > v;
		    for(int i=1;i<=n;i++)
		    {
		    	long long int s=0;
		    	for(int k=0;k<3;k++)
		    	{
		    		if(j/(1<<k)%2==0)
		    			s+=a[i][k];
		    		else
		    			s-=a[i][k];
		    	}
		    	v.push_back(s);
		    	
		    }
		    sort(v.rbegin(),v.rend());
		    long long int ans=0;
		    for(int i=0;i<m;i++)
		    {
		    	ans+=v[i];
		    }
		    ma=max(ma,ans);
			}
			cout<<ma<<endl;
			return 0;

		}