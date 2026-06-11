#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  for(int i = 1; i < 10; i++){
    int k = i * 111;
    if(k < n) continue;
    cout << k << endl;
    break;
  }
}