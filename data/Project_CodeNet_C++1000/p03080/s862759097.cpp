#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
  lli n;
  char c;
  cin>>n;
  unordered_map<char, lli> mp;
  for(lli i=0;i<n;i++)
  {
    cin>>c;
    mp[c]++;
  }
  if(mp['R']>mp['B']) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}