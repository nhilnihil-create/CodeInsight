#include <bits/stdc++.h> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

long long int n,arr[200];
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  

    cin>>n;
    rep(i,1,n)
    	cin>>arr[i];
    sort(arr+1,arr+n+1);
    cout<<arr[n]-arr[1];
}
	