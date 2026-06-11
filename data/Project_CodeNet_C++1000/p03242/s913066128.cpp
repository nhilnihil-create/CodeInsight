#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin >> n;
  
  if(n/100 == 9){
    cout << 1;
  }else{
    cout << 9;
  }
  
  if((n/10)%10 == 9){
    cout << 1;
  }else{
    cout << 9;
  }
  
  if(n%10 == 9){
    cout << 1 << endl;
  }else{
    cout << 9 << endl;
  }
}