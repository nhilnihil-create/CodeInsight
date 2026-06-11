#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  int b=0;
  int r=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='B')b++;
    else r++;
  }
  if(b>= r)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  return 0;
}
  