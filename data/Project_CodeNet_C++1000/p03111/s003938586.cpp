#include<bits/stdc++.h>
#define ll long long
const int N=100005;
using namespace std;
int ans=2e9+7;
int n,C,B,A,l[10];
void dfs(int i,int a,int b,int c,int mp)
{
	if(i==n+1)
	{
		if(!a||!b||!c) return;
		else
		{
			ans=min(ans,abs(a-A)+abs(b-B)+abs(c-C)+mp);
			return;
		}
	}
	dfs(i+1,a,b,c,mp);
	dfs(i+1,a+l[i],b,c,mp+(a==0?0:10));
	dfs(i+1,a,b+l[i],c,mp+(b==0?0:10));
	dfs(i+1,a,b,c+l[i],mp+(c==0?0:10));
}
int main(){
	cin>>n>>A>>B>>C;
	for(int i=1;i<=n;i++) cin>>l[i];
	dfs(1,0,0,0,0);
	cout<<ans;
    return 0;
}