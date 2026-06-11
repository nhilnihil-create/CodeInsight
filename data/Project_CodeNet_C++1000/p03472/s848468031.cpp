#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
long long n,h;
pair<int,int> d[100005];
int main()
{
	cin >> n >> h;
	int maxd=0;
	for(int i=0; i<n; i++)cin >> d[i].second >> d[i].first,maxd=max(maxd,d[i].second);
	
	sort(d,d+n);
	long long sum=0,l=0;
	for(int i=n-1; ~i; i--)
	{
		if(d[i].first<=maxd) break;
		sum+=d[i].first; l++;
		if(sum>=h)
		{
			cout << n-i;
			return 0;
		}
	}
	h-=sum;
	cout << h/maxd+(h%maxd!=0)+l;
	return 0;
}
