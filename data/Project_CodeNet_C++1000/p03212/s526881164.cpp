#include<bits/stdc++.h>
using namespace std;
int n;
int dfs(long long s)
{
  if(s>n)return 0;
  long long  t=s;
  map<int,int>a;
  while(t>0)
  {
    a[t%10]++;
    t/=10;
  }
  int ans;
  if(a[3]==0 ||a[7]==0 || a[5] ==0)ans=0;
  else ans=1;
  vector<int>b{3,7,5};
  for(auto x:b)
    ans+=dfs(s*10+x);
  return ans;
}
  
int main()
{
  
  cin>>n;
  cout<<dfs(0);
  return 0;
}