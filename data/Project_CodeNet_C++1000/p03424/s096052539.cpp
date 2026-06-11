#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;cin >> n;
  for(int i = 0;i < n;i++){
      char x;cin >> x;
      if(x == 'Y'){
          cout << "Four" << '\n';
          return 0;
      }
  }
  cout << "Three" << '\n';
  return 0;
}
