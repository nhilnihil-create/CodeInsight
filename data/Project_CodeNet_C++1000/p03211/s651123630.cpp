#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int m=999;
  for(int i=2;i<s.size();i++)
    m=min(m,abs(753-stoi(s.substr(i-2,3))));
  cout<<m<<endl;
}