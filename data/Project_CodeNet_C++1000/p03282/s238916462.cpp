#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int k;
  cin>>k;
  int n=s.size();
  for(int i=0;i<min(k,n);i++){
    if(s[i]=='1'){
      if(i+1==k){
        cout<<1<<endl;
        return 0;
      }
    }else {
      cout<<s[i]<<endl;
      return 0;
    }
  }
}