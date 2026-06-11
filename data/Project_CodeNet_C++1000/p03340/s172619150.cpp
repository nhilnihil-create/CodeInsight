#include<bits/stdc++.h>
using namespace std;
long long a[210000]={0};
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	int l=1,r=1;
	int sum=a[1],num=a[1];
	long long ans=0;
	//cout<<endl;
	while(r<=n)
	{
		//cout<<sum<<" "<<num<<endl;
		//cout<<"a";
		if(sum==num)
		{
			ans+=r-l+1;
			r++;
			num=num^a[r];
			sum+=a[r];
		}
		else
		{
			num=num^a[l];
			sum=sum-a[l];
			l++;
		}
		
	}
	cout<<ans;
	return 0;
}