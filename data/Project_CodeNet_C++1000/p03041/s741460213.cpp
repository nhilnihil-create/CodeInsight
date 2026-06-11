#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void solve()
{
  int n;int k;cin>>n>>k;
  string s;cin>>s;
  if(s[k-1]=='A')
  s[k-1]='a';
  else if(s[k-1]=='B')
  s[k-1]='b';
  else
  s[k-1]='c';
  
  cout<<s<<endl;
   
}
int32_t main()
{
    rapido;
    int t;
     // cin>>t;
    t=1;
    while(t--)
    solve();
}


