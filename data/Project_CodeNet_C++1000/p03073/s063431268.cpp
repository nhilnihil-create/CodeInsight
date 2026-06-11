#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  long long t=0,u=0;
  cin >> s;
  for(long long i=0;i<s.size();i++){
    if(i%2==0){
      if(s[i]=='0'){
        u++;
      }else{
        t++;
      }
    }else{
      if(s[i]=='0'){
        t++;
      }else{
        u++;
      }
    }
  }
  cout << s.size() - max(t,u) << endl;
  return 0;
}