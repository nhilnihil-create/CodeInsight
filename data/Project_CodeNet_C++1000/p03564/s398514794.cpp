#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

long long int n,k,i;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
    
    
	cin>>n>>k;
	i=1;
	while(n--)
	{
		i=min(i*2,i+k);
	}
	cout<<i;
}
	