#include<bits/stdc++.h>
using namespace std;
const int N=1001;
long long n,x[N],y[N],q[N],t;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
		if((x[i]+y[i]+x[1]+y[1])&1)
		{
			cout<<-1;
			return 0;
		}
	for(int i=30;i>=0;i--)
		q[++t]=1<<i;
	if((x[1]+y[1]+1)&1)
		q[++t]=1;
	cout<<t<<'\n';
	for(int i=1;i<=t;i++)
		cout<<q[i]<<" ";
	cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		if(t==32)
			x[i]++;
		for(int j=1;j<=31;j++)
			if(abs(x[i])>=abs(y[i])&&x[i]>=0)
				cout<<'R',x[i]-=q[j];
			else if(abs(x[i])>=abs(y[i])&&x[i]<0)
				cout<<'L',x[i]+=q[j];
			else if(y[i]>=0)
				cout<<'U',y[i]-=q[j];
			else
				cout<<'D',y[i]+=q[j];
		if(t==32)
			cout<<'L';
		cout<<'\n';
	}
	return 0;
}