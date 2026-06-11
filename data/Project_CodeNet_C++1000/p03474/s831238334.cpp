#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a,b;
  string s;
  cin>>a>>b>>s;
  bool ans=true;
  rep(i,a){
    if(s[i]=='-'){
      ans=false;
    }
  }
  if(s[a]!='-'){
    ans=false;
  }
  for(int i=a+1; i<a+b+1; i++){
    if(s[i]=='-'){
        ans=false;
    }
  }
  if(ans){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}