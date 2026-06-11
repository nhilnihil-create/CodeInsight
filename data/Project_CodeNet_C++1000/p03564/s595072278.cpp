#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K, a = 1, b = 1;
  cin >> N >> K;
  
  for(int i = 0; i < N; i++){
    a *= 2;
    b += K;
    if(a < b) b = a;
    else a = b;
  }
  cout << a << endl;
}