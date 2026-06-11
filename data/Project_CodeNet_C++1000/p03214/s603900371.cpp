#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000;
int n,a[N];
int main()
{
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	double av=1.0*sum/n;
	double ss=1000;
	int id=-1;
	for(int i=1;i<=n;i++)
	{
		double cf=abs(a[i]*1.0-av);
		if(cf<ss)
		{
			ss=cf;
			id=i;
		}
	}
	cout<<id-1<<endl;
}