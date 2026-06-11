#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

long long a,b;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
    
    
    cin>>a>>b;
    cout<<((b-a)*(b-a+1))/2-b;
}
	