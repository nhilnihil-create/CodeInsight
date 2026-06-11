#include <bits/stdc++.h>
using namespace std;

int main() {
  //支払う金額nと一円玉を持っているa枚
  int n,a;
  
  cin >> n >> a;
  
  int b = n / 500;
  
  int res = n - 500 * b;
  
  if(a >= res){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
