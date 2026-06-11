#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

long long int solve(int n)
{
	long long a[n+1];
	a[0]=2,a[1]=1;
	for(int i=2;i<=n;i++)
		a[i]=a[i-1]+a[i-2];
	return a[n];
}
int n;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
    
    
	cin>>n;
	cout<<solve(n);
}
	