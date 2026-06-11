#include<iostream>
#include<cstring>
using namespace std;
const int N=200020;
long long s,n,a[N],ans=0;
int main()
{
	cin>>n;
	//memset(last,0,sizeof(last));
	for(int i=1;i<=n;i++) cin>>a[i];
	long long j=0;
	long long suma=0,sumb=0;
	for(int i=1;i<=n;i++)
	{
		while(j+1<=n&&sumb+a[j+1]==(suma^a[j+1]))
		{
			suma^=a[j+1];
			sumb+=a[j+1];
			j++;
		}
		ans+=j-i+1;
		suma^=a[i];
		sumb-=a[i];
	}
	cout<<ans;
	return 0;
}
