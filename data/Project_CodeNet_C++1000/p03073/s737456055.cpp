#include<bits/stdc++.h>
using namespace std;
int main() {
  int c=0;
  string s; cin>>s;
  for(int i=0;i<s.size();i++) if((i%2&&s[i]=='1')||(i%2==0&&s[i]=='0')) c++;
  cout<<min(c,(int)s.size()-c);
}