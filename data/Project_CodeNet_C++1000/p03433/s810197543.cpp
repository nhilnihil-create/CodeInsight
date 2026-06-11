#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,a;
  cin >> n;
  cin >> a;
  n = n % 500;
  if (a < n){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }

}