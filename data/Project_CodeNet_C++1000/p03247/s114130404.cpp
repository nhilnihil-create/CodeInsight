#include <bits/stdc++.h>
#define int long long
#define iris 1000000007
using namespace std;

int x[1010],y[1010],arr[32];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,a,b,i,j;
	bool flag;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		if(!i)
		{
			flag=(abs(x[i]+y[i])&1);
		}
		else if((abs(x[i]+y[i])&1)!=flag)
		{
			cout<<"-1\n";
			return 0;
		}
	}
	
	if(flag)
	{
		m=31;
		cout<<m<<'\n';
		for(i=0;i<m;i++)
		{
			arr[i]=(1<<(31-i-1));
			cout<<arr[i]<<" \n"[i==m-1];
		}
	}
	else
	{
		m=32;
		cout<<m<<"\n";
		for(i=0;i<m;i++)
		{
			arr[i]=(1<<max(31-i-1, 0LL));
			cout<<arr[i]<<" \n"[i==m-1];
		}
	}
	
	for(i=0;i<n;i++)
	{
		a=b=0;
		for(j=0;j<m;j++)
		{
			if(abs(x[i]-a)>abs(y[i]-b))
			{
				if(a<x[i])
				{
					a+=arr[j];
					cout<<"R";
				}
				else
				{
					a-=arr[j];
					cout<<"L";
				}
			}
			else
			{
				if(b<y[i])
				{
					b+=arr[j];
					cout<<"U";
				}
				else
				{
					b-=arr[j];
					cout<<"D";
				}
			}
		}
		cout<<"\n";
//		cout<<a<<' '<<b<<'\n';
	}
	
	return 0;
}