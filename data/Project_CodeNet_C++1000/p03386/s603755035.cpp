#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t a, b ,k;
  cin >> a >> b >> k;
  for (int64_t i=a ; i<=b ; i++){
    if ( i-a<=k-1 || b-i<=k-1){
      cout << i <<endl;
    }
  }
}