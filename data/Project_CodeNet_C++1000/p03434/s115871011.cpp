#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  //入力
  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  
  int alice = 0, bob = 0;
  int b = 0, c;
  
  for (int i = 0; i < n; i++) {
    
    //最も大きいカードの数字をbに、そのカードのa(n)の中での位置をcに代入
    for (int j = 0; j < n; j++) {
      if (b < a.at(j)) {
        b = a.at(j);
        c = j;
      }
    }
    
    //iが偶数のときalice, 奇数の時bob
    if (i % 2 == 0) {
      alice += b;
    }
    else {
      bob += b;
    }
    
    //引いたカードの数字を0にする
    a.at(c) = 0;
    b = 0;
    
  }
  
  cout <<  alice - bob << endl;
  
}