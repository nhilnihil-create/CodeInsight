#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
  cin >> n;
  if (n % 4 == 0 || n % 7 == 0) cout << "Yes";
  else {
    while (n > 0 && n % 7 != 0){
      n -= 4;
    }
    if (n % 7 == 0) cout << "Yes";
    else cout << "No";
  }
}
