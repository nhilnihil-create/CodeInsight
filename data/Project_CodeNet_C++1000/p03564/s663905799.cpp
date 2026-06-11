#include <bits/stdc++.h>
using namespace std;

int main() {
   
  int n, k;
  cin >> n >> k;
  int x = 1;
  
  for (int i = 1; i < n+1; i++){
    if (x > k){
       x += k;
       continue;
       }
    
    x *= 2;
  }
  
  cout << x << endl;
}
