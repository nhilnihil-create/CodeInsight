#include <bits/stdc++.h> 
using namespace std; 
#define rep(i,a,b)		for(int i=a;i<=b;i++)

int n;
set<int> s = {1,2,3,5,6,9,10,13,17,23,27};
int main() 
{ 

	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    n%=28;
    if(s.count(n))
    	cout<<"No";
    else
    	cout<<"Yes";

} 
