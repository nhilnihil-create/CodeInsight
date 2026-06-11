#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int64_t n;
  cin >> s >> n;
  n--;
  int z=0;
  while(z<s.size()&&s.at(z)=='1')
    z++;
  int ans=0;
  if(z>n)
    ans=1;
  else
    ans=s.at(z)-48;
  cout << ans << endl;
  return 0;
}