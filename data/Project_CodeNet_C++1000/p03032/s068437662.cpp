#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
int n,m,a[maxn],b[maxn],ans=0;
int main()
{
    scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	int k=min(n,m);
	for(int l=0;l<=k;l++)
	{
		for(int r=0;r<=k-l;r++)
		{
			for(int i=0;i<l;i++) b[i]=a[i];
			for(int j=0;j<r;j++) b[l+j]=a[n-j-1];
			sort(b,b+l+r);
			int k=0,temp=0;
			while(k+l+r<m&&b[k]<0)
				k++;
			while(k<l+r)
			{
				temp+=b[k];
				k++;
			}
			
		ans=max(ans,temp);
		}
	}
	printf("%d\n",ans);
    return 0;
}