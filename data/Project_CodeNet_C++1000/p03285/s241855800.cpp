#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  bool a=0;
  
  rep(i,30){
    rep(j,30){
      if(i*4 + j*7 == n){
        a=1;
      }
    }
  }
  if(a){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}