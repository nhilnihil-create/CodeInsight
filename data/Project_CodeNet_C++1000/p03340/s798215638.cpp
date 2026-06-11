#include<iostream>
using namespace std;
long long n,a[1001001],suma,sumb,ret,j;
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<=n;i++)
	{
		while(j+1<=n&&(suma^a[j+1])==(sumb+a[j+1]))
		{
			j++;
			suma^=a[j];
			sumb+=a[j];
		}
		ret+=j-i+1;
		suma^=a[i];
		sumb-=a[i];
	}
	cout<<ret;
 	return 0;
}