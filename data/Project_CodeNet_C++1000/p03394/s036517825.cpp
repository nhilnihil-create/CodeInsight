#include<iostream>
using namespace std;
int n;
bool f[1<<15];
main()
{
	cin>>n;
	if(n<6)
	{
		cout<<(n==3?"2 5 63":n==4?"2 5 20 63":"2 5 20 30 63")<<endl;
	}
	else
	{
		int sum=0,i=2;
		for(;i<=3e4;i++)
		{
			if(i%2==0||i%3==0)
			{
				f[i]=1;
				sum+=i;
				n--;
				if(n==0)break;
			}
		}
		i++;
		if(sum%6==2)
		{
			f[8]=0;
			while(i%6)i++;
			f[i]=1;
		}
		else if(sum%6==3)
		{
			f[9]=0;
			while(i%6)i++;
			f[i]=1;
		}
		else if(sum%6==5)
		{
			f[9]=0;
			while(i%6!=4)i++;
			f[i]=1;
		}
		int s=0;
		for(int i=0;i<=3e4;i++)
		{
			if(f[i])
			{
				if(s++)cout<<" ";
				cout<<i;
			}
		}
		cout<<endl;
	}
}
