#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans=754,n;
  for(int i=0;i<s.size()-2;i++){
    n=abs(753-(100*(s.at(i)-48)+10*(s.at(i+1)-48)+s.at(i+2)-48));
    ans=min(ans,n);
  }
  cout << ans << endl;
  return 0;
}