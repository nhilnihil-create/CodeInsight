#include <iostream>
using namespace std;
int n,cnt[4];
double f[310][310][310];
double DFS(int a,int b,int c)
{
	if(a==0&&b==0&&c==0) return 0;
	else if(f[a][b][c]) return f[a][b][c];
	double ans=1.0*n/(a+b+c);
	if(a) ans+=(1.0*a/(a+b+c))*DFS(a-1,b,c);
    if(b) ans+=(1.0*b/(a+b+c))*DFS(a+1,b-1,c);
    if(c) ans+=(1.0*c/(a+b+c))*DFS(a,b+1,c-1);
    return f[a][b][c]=ans;
}
int main()
{
	cin>>n;
	for(int x,i=1;i<=n;i++) cin>>x,cnt[x]++;
	printf("%.14lf\n",DFS(cnt[1],cnt[2],cnt[3]));
	return 0;
}