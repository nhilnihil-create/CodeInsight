#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans=0,c;
  for(int i=0;i<s.size();i++){
    c=0;
    while(i+c<s.size()&&(s.at(c+i)=='A'||s.at(c+i)=='C'||s.at(c+i)=='G'||s.at(c+i)=='T'))
      c++;
    ans=max(ans,c);
  }
  cout << ans << endl;
  return 0;
}