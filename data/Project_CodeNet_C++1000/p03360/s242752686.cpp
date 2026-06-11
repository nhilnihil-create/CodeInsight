#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

int arr[3],sum=0,k;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
    
	cin>>arr[0]>>arr[1]>>arr[2]>>k;
	sort(arr,arr+3); 
	while(k--)
	{
		arr[2]*=2;
	}	
	for(int i=0;i<3;i++)
		sum+=arr[i];
	cout<<sum;
}
	