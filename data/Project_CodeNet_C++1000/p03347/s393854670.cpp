#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	//ifstream in("test.txt");
	//cin.rdbuf(in.rdbuf());
	int n;
	cin >> n;
	vector<ll> a(n),b(n);
	for(int i = 0 ;i<n;i++)cin >> a[i];
	for(int i = 0 ;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			b[i]=a[i];
		}
	}
	b.back()=a.back();
	reverse(b.begin(),b.end());

	for(int i = 0;i<n-1;i++)
	{
		b[i+1] =max<ll>({0, b[i]-1,b[i+1]});
	}
	reverse(b.begin(),b.end());
	ll ans = 0;


	for(int i = 0;i<n;++i)
	{
		if(a[i]<b[i]||a[i]>i)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	a.push_back(0);
	n++;
	ans = 0;
	reverse(a.begin(),a.end());
	for(int i = 0;i<n-1;i++)
	{
		if(a[i]!=a[i+1]+1)
		{
			ans += a[i+1];
		}
	}
	cout<<ans<<endl;

	return 0;
}