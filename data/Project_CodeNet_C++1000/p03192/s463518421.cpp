#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s; cin>>s;
  int ans=0;
  for(auto c:s){
    if (c=='2') ans++;
  }
  cout<<ans<<endl;
  return 0;
}
