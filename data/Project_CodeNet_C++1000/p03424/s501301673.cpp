#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

set<char> s;
int n;
char c;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
    
	cin>>n;
	while(n--)
	{
		cin>>c;
		s.insert(c);
	}
	if(s.size()==3)
		cout<<"Three";
	else
		cout<<"Four";
}
	