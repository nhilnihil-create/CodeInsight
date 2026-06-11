#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  int a;
  int b;
  cin >> n;
  cin >> a;
  cin >> b;
  if(n * a < b){
    cout << n * a << endl;
  }else{
    cout << b << endl;
  }
  return 0;
}