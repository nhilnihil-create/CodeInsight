// author: lkx
// Problem:
// ID:
#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define PH push

const int MOD=1e9+7;

string s;
int k;
int f[305][305][305];
int ans=0;

int main()
{
	cin>>s>>k;
	for(int i=s.size()-1;i>=0;i--)
	{
		for(int j=i;j<s.size();j++)
		{
			for(int ch=0;ch<=k;ch++)
			{
				if(i==j) f[i][j][ch]=1;
				else if(i+1==j) f[i][j][ch]=((ch>0)?2:1+(s[i]==s[j]));
				else 
				{
					
					f[i][j][ch]=max(f[i+1][j][ch],f[i][j-1][ch]);
					if(s[i]==s[j]) f[i][j][ch]=max(f[i+1][j-1][ch]+2,f[i][j][ch]);
					if(ch>0) f[i][j][ch]=max(f[i+1][j-1][ch-1]+2,f[i][j][ch]);
				}
			//	printf("i=%d j=%d ch=%d res=%d\n",i,j,ch,f[i][j][ch]);
				ans=max(ans,f[i][j][ch]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
