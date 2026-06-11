#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  string s;
  cin>>a>>b>>s;
  bool f=1;
  for(int i=0;i<s.size();i++)
      f&=(i==a?(s.at(i)=='-'):(s.at(i)>='0'&&s.at(i)<='9'));
  cout<<(f?"Yes":"No")<<endl;
}