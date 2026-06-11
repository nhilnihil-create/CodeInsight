#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  int x = 1;
  int y = 1;
  
  for (int i = 0; i < N; i++){
    y *= 2;
    if (x + K <= y){
      x += K;
    }else{
      x *= 2;
    }
  }
  
 cout << x << endl;
}