#include<bits/stdc++.h>
using namespace std;
long long n,a[200200];
vector<long long> v;
map<int,int> m;
long long dd=0;
int bbb(int n)
{
	int s=1;
	while(true)
	{
		s*=2;
		if(s>n)
		  break;
	}
	return s;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
		if(a[i]>dd)
		  dd=a[i];
    }
    long long s=1,ans=0;
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		if(m[a[i]]<=0)continue;
		int x=a[i];
		int y=bbb(x)-x;
		if(m[y])
		{
			m[x]--;
			m[y]--;
			if(m[y]>=0)
			ans++;
		}
	}
	cout<<ans;
	return 0;
}