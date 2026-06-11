#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

string a,b;
bool flag = false;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
    
    
	cin>>a>>b;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	if(a<b)
		cout<<"Yes";
	else
		cout<<"No";
}
	