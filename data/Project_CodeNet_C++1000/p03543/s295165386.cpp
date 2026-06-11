#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  if (n % 1110 <= 9){
  cout << "Yes" << endl;
  }
  else if ((n - (n/1000)*1000) % 111 == 0){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
  
  