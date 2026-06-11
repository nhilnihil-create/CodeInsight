#include<bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int main()
{
	long long s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>a[i];
	int j=0,suma=0,sumb=0;
	for(int i=1;i<=n;i++)
	{
		while(j+1<=n&&suma+a[j+1]==(sumb^a[j+1]))
		{
			j++;
			suma=suma+a[j];
			sumb=sumb^a[j];
		}
		suma=suma-a[i];
		sumb=sumb^a[i];
		s=s+j-i+1;
		
	}
	cout<<s;
}