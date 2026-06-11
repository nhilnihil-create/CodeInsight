#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin>>s;
  int k;
  cin>>k;
  bool hantei=false;
  for(int i=0;i<s.size();i++){
    int a=s[i]-'0';
    if(a==1)hantei=true;
    else {
      cout<<a<<endl;
      return 0;
    }
    if(hantei&&i+1==k){
      cout<<1<<endl;
      return 0;
    }
  }
  return 0;
}
    