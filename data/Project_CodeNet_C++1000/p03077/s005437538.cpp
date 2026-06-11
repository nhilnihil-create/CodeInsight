#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll arr[5],n;
	cin>>n;
	for(int i=0;i<5;i++)
		cin>>arr[i];
	sort(arr,arr+5);
	ll min=arr[0];
	ll t=4;
	if(n%min==0)
		t+=n/min;
	else
		t+=n/min+1;
	cout<<t;
	return 0;
}
