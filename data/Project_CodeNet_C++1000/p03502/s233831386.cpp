#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

int ds(int n)
{
	int ans =0;
	while(n)
		ans+=n%10,n/=10;
	return ans;
}

int n;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
    
	cin>>n;
	if(n%(ds(n))==0)
		cout<<"Yes";
	else
		cout<<"No";
}
	