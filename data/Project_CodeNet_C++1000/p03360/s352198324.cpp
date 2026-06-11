#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c; cin >> a >> b >> c;
  int k; cin >> k;
  int i = 0;
  int max_num = max(max(a,b),c);
  if(max_num == a){
    while(i < k){
      a *=2;
      i++;
    }
  }
  else if(max_num == b){
    while(i < k){
      b *=2;
      i++;
    }
  }
  else {
    while(i < k){
      c *=2;
      i++;
    }
  }
  cout << a + b +c;
}
  