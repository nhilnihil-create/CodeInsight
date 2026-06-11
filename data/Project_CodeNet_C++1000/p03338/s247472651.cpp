#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

int n,maxi=INT_MIN,cnt=0,ans;
string a,x,y;
set<char> s1,s2;

int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
    
    cin>>n>>a;
    x = "";
    y = a;
    int temp = n;
    for(int i = 1 ;i<temp;i++)
    {
    	cnt=0;
    	s1.clear(),s2.clear();
    	x += y.front();
    	y = a.substr(i,string::npos);
    	for(auto it: x)
    		s1.insert(it);
    	for(auto it : y)
    		s2.insert(it);

    	for(auto it : s2)
    	{
    		if(s1.find(it)!=s1.end())
    			cnt++;
    	}
    	ans = max(ans,cnt);
    }
    cout<<ans;
}
	