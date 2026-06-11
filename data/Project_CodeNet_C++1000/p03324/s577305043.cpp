#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

long long d,n;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
   
    
    cin>>d>>n;
    if(n<100)
    	cout<<pow(100,d)*n;
    else
    	cout<<setprecision(20)<<pow(100,d)*n+pow(100,d);
}
	