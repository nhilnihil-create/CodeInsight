#include <bits/stdc++.h> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7
string a,b;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cin>>a>>b;
    int n=a.length();
    bool ans = false;
    for(int i=0;i<a.size();i++)
    {
    	if(a==b)
    	{
    		ans = true;
    		break;
    	}
    	b=b.back()+b.substr(0,b.size()-1);
    }
    if(ans)
    	cout<<"Yes";
    else
    	cout<<"No";
}
	