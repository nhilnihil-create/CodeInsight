#include<bits/stdc++.h>
using namespace std;
int cn1[100005];
int cn2[100005];
int mx1,mx2,n1,n2;
int main()
{
	int n;
	cin>>n;
	int a;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(i%2)
			cn1[a]++;
		else
			cn2[a]++;
	}
	for(int i=1;i<=100004;i++)
	{
		if(mx1<cn1[i])
		{
			mx1=cn1[i];
			n1=i;
		}
		if(mx2<cn2[i])
		{
			mx2=cn2[i];
			n2=i;
		}
	}
	if(n1==n2)
	{
		int mx22=0;
		for(int i=1;i<=100004;i++)
			if(i!=n1&&mx22<cn2[i])
				mx22=cn2[i];
		int mx12=0;
		for(int i=1;i<=100004;i++)
			if(i!=n2&&mx12<cn1[i])
				mx12=cn1[i];
		cout<<n-max((mx1+mx22),(mx12+mx2));
		return 0;
	}
	cout<<n-(mx1+mx2);

	return 0;
}