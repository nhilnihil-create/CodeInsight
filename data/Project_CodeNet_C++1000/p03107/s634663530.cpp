#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  char n='0';
  int cnt=0,ans=0;
  for(int i=0;i<s.size();i++){
    if(cnt==0){
      n=s.at(i);
      cnt++;
    }else{
      if(n==s.at(i)){
        cnt++;
      }else{
        cnt--;
        ans+=2;
      }
    }
  }
  cout << ans << endl;
  return 0;
}