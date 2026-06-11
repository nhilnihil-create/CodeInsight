#include<iostream>
using namespace std;
int main(){
  int n=15;
  string s;
  cin>>s;
  for(int cnt;cnt<s.size();cnt++)
    if(s[cnt]=='x')n--;
  if(n<8)cout<<"NO";
  else cout<<"YES";
}