#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <queue>
#include <deque>
#define ll long long
#define MP make_pair
#define PII pair<int, int>
#define F first
#define S second
using namespace std;
int n;
ll a[200010];
ll ans=1e18;
void div(int l,int r,ll &x,ll &y)
{
	int mid;
	ll res=1e18;
	int li=l,ri=r;
	while (li<ri)
	{
		mid=(li+ri)/2;
		//cout <<l<<" "<<r<<" "<<mid<<" "<<x<<" "<<y<<" "<<res<<" "<<(a[mid]-a[l-1])<<" "<<(a[r]-a[mid])<<" #\n";
		if (res>abs((a[mid]-a[l-1])-(a[r]-a[mid])))
		{
			res=abs((a[mid]-a[l-1])-(a[r]-a[mid]));
			x=a[mid]-a[l-1];
			y=a[r]-a[mid];
		}
		if (a[mid]-a[l-1]<a[r]-a[mid]) li=mid+1;
		else ri=mid; 
	}
}
int main()
{
	cin >>n;
	for (int i=0;i<n;i++)
	{
		int x;
		cin >>x;
		a[i+1]=x+a[i];
		//cout <<a[i+1]<<" ##\n";
	}
	for (int i=2;i<n-1;i++)
	{
		//cout <<i<<" #################\n";
		ll w=0,x=0,y=0,z=0;
		div(1,i,w,x);
		//cout <<w<<" "<<x<<" #####\n";
		div(i+1,n,y,z);
		//cout <<y<<" "<<z<<" #####\n";
		ll mx=max(max(w,x),max(y,z));
		ll mn=min(min(w,x),min(y,z));
		ans=min(ans,mx-mn);
	}
	cout <<ans;
	return 0;
}