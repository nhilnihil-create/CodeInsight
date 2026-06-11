#include <bits/stdc++.h>
using namespace std;
 
int main() {

  int i = 0;
  //入力を受け取る
  string M;
  cin >> M;
  
  if(M[0] =='1') {
    i++;
  }
  if(M[1] =='1') {
    i++;
  }
  if(M[2] =='1') {
    i++;
  }
  
  cout << i;
}