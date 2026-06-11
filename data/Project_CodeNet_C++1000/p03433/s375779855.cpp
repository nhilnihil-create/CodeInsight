#include <bits/stdc++.h>
using namespace std;

int main() {
  int total, one;
  
  cin >> total >> one;
  if(total%500 <= one){ // 500円硬貨で払いきれない分を1円硬貨で払えるかを調べる
    cout << "Yes" << endl;
  } else{
    cout << "No" << endl;
  }
}