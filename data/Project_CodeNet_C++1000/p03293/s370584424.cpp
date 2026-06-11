#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s,t;
  cin>>s>>t;
  bool ans=false;
  rep(i,s.size()){
    char fir=s.back();
    s.pop_back();
    s=fir+s;
    if(s==t){
      ans=true;
    }
  }
  if(ans){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}