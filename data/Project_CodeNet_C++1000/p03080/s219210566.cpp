#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int N=1005;
const int MOD=1e9+7;
 
 
int32_t main()
{
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  string s;
  cin>>s;
  int count=0;
  for(int i=0;i<n;i++)
  {
  	if(s[i]=='R')
  	{
  		count++;
  	}
  }
  int t=n-count;
  if(count>t)
  {
  	cout<<"Yes"<<endl;
  }
  else
  {
  	cout<<"No"<<endl;
  }
  
}
