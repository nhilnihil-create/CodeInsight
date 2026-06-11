#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int c=0;
  int l=0;
  for(int i=1;i<s.size();i++){
    if(s.at(i)>='a')
      l++;
    if(i>1&&i<s.size()-1&&s.at(i)=='C')
      c++;
  }
  cout<<(s.at(0)=='A'&&c==1&&l==s.size()-2?"AC":"WA")<<endl;
}