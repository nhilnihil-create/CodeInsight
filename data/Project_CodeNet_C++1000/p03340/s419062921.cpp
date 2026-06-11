#include<iostream>
using namespace std;
/*
思路：
尺取法，可以发现第i+1个数最小符合条件的右端点一定大于第i个数最小符合条件的右端点，
所以可以存储上一个数最小符合条件的右端点，从这个点开始枚举 
*/
long long a[300100];
int main()
{
	long long n,i;
	cin>>n;
	long long ans=0;
	for(i=1;i<=n;i++)
		cin>>a[i];
	long long j=0,suma=0,sumb=0; 
	for(i=1;i<=n;i++)
	{
		while(j+1<=n && (suma^a[j+1])==sumb+a[j+1])
		{
			suma^=a[j+1];
			sumb+=a[j+1];
			j++;
		}
		ans+=j-i+1; 
		suma^=a[i];
		sumb-=a[i];
	}
	cout<<ans<<endl;
 	return 0;
}
