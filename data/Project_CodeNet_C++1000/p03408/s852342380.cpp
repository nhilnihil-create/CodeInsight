#include <bits/stdc++.h>
#include <iomanip> 
using namespace std; 
#define rep(i,a,b)		for(long int i=a;i<=b;i++)
#define MOD 1e9+7

int n,m,check;
unordered_map<string,int> ans;
int cnt=INT_MIN;
string temp;
int main() 
{ 
	ios::sync_with_stdio(false);
    cin.tie(NULL);  
   
	cin>>n;
	rep(i,1,n)
	{
		cin>>temp;
		ans[temp]+=1;
	}
	cin>>m;
	rep(i,1,m)
	{
		cin>>temp;
		ans[temp]-=1;
	}
	for(auto it:ans)
	{
		check = it.second;
		cnt = max(check,cnt);
	}
	cout<<max(0,cnt);

}
	