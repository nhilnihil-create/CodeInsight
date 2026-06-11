#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B;
int n;
const int N=5010;
int a[N],pos[N];
ll f[N][N];

int main()
{
	scanf("%d%lld%lld",&n,&A,&B);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for(int i=0;i<=n;i++)f[0][i]=B*i;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			f[i][j]=f[i-1][j];
			if(j) f[i][j]=min(f[i][j],f[i][j-1]+(pos[j]>i ? B:A) );
			if(j&&pos[j]==i) f[i][j]=min(f[i][j],f[i-1][j-1]);
//			cout<<i<<" "<<j<<" :: "<<f[i][j]<<endl;
		}
	}
	cout<<f[n][n]<<endl;
}
