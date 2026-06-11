#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

int n,arr[100],x,sum=0,ans;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
	cin>>n>>x;
	rep(i,0,n-1)
		cin>>arr[i],sum+=arr[i];
	sort(arr,arr+n);
	x-=sum;
	n+=x/arr[0];
	cout<<n;

}
	