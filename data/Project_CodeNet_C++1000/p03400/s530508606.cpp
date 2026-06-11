#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

int ans = 0,n,d,x,a[102],k;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
   
	cin>>n>>d>>x;
	ans = x+n;
	rep(i,1,n)
	{
		cin>>a[i];
		k=1;
		while(((k++)*a[i]+1)<=d)
			ans++;
	}
	cout<<ans;
}
	