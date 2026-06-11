#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int a, count, min = 10000000;
  
  for (int i = 0; i < n; i++){
    cin >> a;
    count = 0;
    while (a % 2 == 0){
      a /= 2;
      count++;
    }
    if (count < min){
      min = count;
    }
  }
  
  cout << min << endl;
        
}
