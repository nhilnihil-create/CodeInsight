#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n;
  cin>>n;
  vector<char> s(n);
  rep(i,n)cin>>s[i];
  rep(i,n){
    if(s[i]=='Y'){
      cout<<"Four"<<endl;
      return 0;
    }
  }
    cout<<"Three"<<endl;
  }