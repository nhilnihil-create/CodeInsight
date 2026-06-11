#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<char> a(n);
  vector<int> b(4);
  rep(i,n){
    cin >> a[i];
  }
  
  rep(i,n){
    if(a[i] == 'P'){
      b[0] = 1;
    }else if(a[i] == 'W'){
      b[1] = 1;
    }else if(a[i] == 'G'){
      b[2] = 1;
    }else{
      b[3] = 1;
    }
  }
  
  int num=0;
  rep(i,4){
    num += b[i];
  }
  
  if(num == 3){
    cout << "Three" << endl;
  }else{
    cout << "Four" << endl;
  }
  
  return(0);
}