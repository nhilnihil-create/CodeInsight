#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001];
long long pl[100001],mi[100001];
int main()
{
	long long n;
	cin>>n; 
	long long ans=0,sum1=0,sum2=0,sum3=0;
	for(int i=1;i<=n;i++)
	{	
		cin>>a[i];
		sum1+=a[i];
	}
	int t1=0,t2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		sum2+=b[i];
		if(b[i]>a[i])
		{
			t1++;
			pl[t1]=b[i]-a[i];
			sum3+=pl[t1];
			ans++;
		}
		else if(b[i]<a[i])
		{
			t2++;
			mi[t2]=a[i]-b[i];
		}
	}
	sort(pl,pl+t1+1);
	sort(mi,mi+t2+1);
	reverse(mi,mi+t2+1);
	if(sum1<sum2)
	{
		cout<<"-1\n";
		return 0;
	}
	if(ans==0)
	{
		cout<<ans<<endl;
		return 0;
	}
	for(int i=0;i<=t2*2;i++)
	{
		if(mi[i]>=sum3)
		{
			ans++;
			break;
		}
		else
		{
			sum3-=mi[i];
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}