#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b; 
}
int sum=0;
int f[4];
int main()
{
	cin>>f[1]>>f[2]>>f[3];
	sort(f+1,f+4,cmp);
	if((f[1]+f[2]+f[3])%2==0)
	{
		int b=0;
		if(f[1]%2==1)
			f[1]++,f[2]++,sum++;
		for(int i=2;i<=3;i++)
		{
			int s=f[1]-f[i];
			if(s%2==1 && b==0)
				sum++,b++;
			sum+=s/2;
		}
	}
	else
	{
		int b=0;
		if(f[1]%2==0)
			f[1]++,f[2]++,sum++;
		for(int i=2;i<=3;i++)
		{
			int s=f[1]-f[i];
			if(s%2==1 && b==0)
				sum++,b++;
			sum+=s/2;
		}
	}
	cout<<sum<<endl;
return 0;
}