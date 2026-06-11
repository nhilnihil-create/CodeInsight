#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

set<int> v;
int a,b,k;

int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
    
	cin>>a>>b>>k;
	for(int i=a;i<=min(a+k-1,b);i++)
		v.insert(i);
	for(int i=max(b-k+1,a);i<=b;i++)
		v.insert(i);
	for(auto it:v)
		cout<<it<<" ";
}
	