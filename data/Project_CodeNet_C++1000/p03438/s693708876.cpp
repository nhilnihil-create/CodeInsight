#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n),b(n);
	for(int i = 0;i<n;i++)
	cin >> a[i];
	for(int i = 0;i<n;i++)
	cin >> b[i];
	ll c= 0,d =0;

	for(int i = 0;i<n;i++)
	{
		if(b[i]-a[i]<0)
		{
			d += abs(b[i]-a[i]);
		}
		else 
		{
			c += (b[i]-a[i])/2;
		}
	}
	//cout<<c<<' '<<d<<endl;
	if(c<d)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
