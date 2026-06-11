#include <iostream>
#include <cmath>
using namespace std;
int a[10],l[10],X,y,z,ans=1e9,n;
inline void dfs(int x)
{
	if(x==n+1)
	{
		int cnt=0,A=0,B=0,C=0,now=n*10-30;
		for(int i=1;i<=n;i++)
		{
			A+=(a[i]==1)*l[i];
			B+=(a[i]==2)*l[i];
			C+=(a[i]==3)*l[i];
			now-=(a[i]==0)*10;
		}
		if(!A||!B||!C) return ;
		ans=min(ans,now+abs(A-X)+abs(B-y)+abs(C-z));
		return ;
	}
	for(int i=0;i<=3;i++)
		a[x]=i,dfs(x+1);
}
int main(int argc, char** argv) {
	cin >> n >> X >> y >> z;
	for(int i=1;i<=n;i++) cin >> l[i];
	dfs(1);
	cout << ans;
	return 0;
}