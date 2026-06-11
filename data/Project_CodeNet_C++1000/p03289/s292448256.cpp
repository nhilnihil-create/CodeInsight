#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int cnt=0,count=0;
  cin >> s;
  for(int i=2;i<s.size()-1;i++)if(s[i]=='C')cnt++;
  for(int i=0;i<s.size();i++)if(isupper(s[i]))count++;
  if(cnt==1 && s[0]=='A' && count==2)cout << "AC" << endl;
  else cout << "WA" << endl;
}
  