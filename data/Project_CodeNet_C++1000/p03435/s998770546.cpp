#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	vector<vector<int>> c(3,vector<int>(3));
	rep(i,3) rep(j,3) cin>>c[i][j];
	for(int a=0;a<=c[0][0];a++)
	{
		vector<int> b(3);
		rep(j,3)
		{
			b[j]=c[0][j]-a;
		}
		bool flag=true;
		rep(i,2)
		{
			vector<int> A(3);
			rep(j,3)
			{
				A[j]=c[i+1][j]-b[j];	
			}
			rep(j,2)
			{
				if(A[j]!=A[j+1])
				{
					flag=false;
					break;
				}
			}
		}
		if(flag)
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}
