#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int x,cnt=0;
  cin>>s;
  
  for(int i=0; i<s.size(); ++i){
    if(s[i] == 'o'){
      ++cnt;
    }
  }
  
  x = 15 - s.size();
  if(cnt + x >= 8){
    cout<<"YES\n";
  }else cout<<"NO\n";
}
