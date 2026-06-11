#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100001]={0},f[100001]={0};
	for(int i=2;i<=100001;i++)
	{
		if(a[i]==0)
		{
			for(int j=i*2;j<=100001;j+=i)
			{
				a[j]=1;
			}
		}
	}
	a[1]=1;
	a[2]=0;
	for(int i=2;i<=100001;i++)
	{
		if(a[i]==0&&a[(i+1)/2]==0&&i%2!=0)
		{
			f[i]=f[i-1]+1;
		}else{
			f[i]=f[i-1];
		}
	}
	int n,l[100001],r[100001];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		cout<<f[r[i]]-f[l[i]-1]<<endl;
	 } 
	return 0;	
} 