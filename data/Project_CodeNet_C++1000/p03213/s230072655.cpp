#include<bits/stdc++.h>
using namespace std;
long long a,b,cnt[100],ans;
void dfs(int x,int a1,bool a2)
{
	if(a1==2&&a2)
	{
		ans++;
		return;
	}
	if(x>97)return;
	dfs(x+1,a1,a2);
	if(cnt[x]>=4&&a1<2)dfs(x+1,a1+1,a2);
	if(cnt[x]>=2&&!a2)dfs(x+1,a1,1);
	if(cnt[x]>=14&&!a2&&a1<2)dfs(x+1,a1+1,1);
	if(cnt[x]>=24&&!a1)dfs(x+1,2,a2);
	if(cnt[x]>=74&&!a1&&!a2)dfs(x+1,2,1);
}
int main()
{
	cin>>a;
	for(int s=2;s<=a;s++)
	{
		b=s;
		for(int v=2;v<=a;v++)
		{
			if(b%v==0)
			{
				cnt[v]++;
				b/=v;
				v--;
			}
		}
	}
	dfs(2,0,0);
	cout<<ans<<endl;
}