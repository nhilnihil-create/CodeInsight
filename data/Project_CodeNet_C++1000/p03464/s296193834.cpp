#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll a[100000];
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(a[n-1]!=2)
	{
		cout<<-1<<endl;
		return 0;
	}
	ll l=1;ll r=1;
	for(int i=n-2;i>-1;i--)
	{
		ll tmpl,tmpr;
		tmpl=a[i+1]*l/a[i];
		if((a[i+1]*l)%a[i]!=0)
			tmpl++;
		tmpr=(a[i+1]*(r+1)-1)/a[i];
		if(tmpl>tmpr)
		{
			cout<<-1<<endl;
			return 0;
		}
		if(a[i]*tmpl<a[i+1]*l)
			tmpl=tmpr;
		l=tmpl;r=tmpr;
	}
	l=l*a[0];
	r=r*a[0]+a[0]-1;
	cout<<l<<" "<<r<<endl;
	return 0;
}