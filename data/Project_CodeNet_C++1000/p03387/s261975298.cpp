#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[4],ans=0;
	cin>>a[1]>>a[2]>>a[3];
	while(a[1]!=a[2]||a[2]!=a[3]||a[1]!=a[3])
	{
		sort(a+1,a+4);
		if(a[2]!=a[3])
		{
			a[1]++;
			a[2]++;
			ans++;
		}
		else
		{
			a[1]+=2;
			ans++;	
		}
	}
	cout<<ans<<endl;
}