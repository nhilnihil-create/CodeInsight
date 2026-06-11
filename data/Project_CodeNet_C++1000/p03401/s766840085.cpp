#include<iostream>
#include<math.h>
using namespace std;
const int N=1e5+10;
long long a[N],sum[N];
// 0~tmp-1 tmp+1-n 
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n+1;i++)
	{
		sum[i]=sum[i-1]+abs(a[i]-a[i-1]);
		//cout<<i<<" "<<sum[i]<<endl;
	}
	int tmp=1;
	while(tmp<=n)
	{
		//cout<<tmp<<" "<<sum[n+1]-sum[tmp+1]<<" "<<sum[tmp-1]-sum[0]<<" "<<abs(a[tmp+1]-a[tmp-1])<<endl;
		cout<<sum[n+1]-sum[tmp+1]+sum[tmp-1]-sum[0]+abs(a[tmp+1]-a[tmp-1])<<endl;
		//cout<<endl;
		tmp++;
	}
}