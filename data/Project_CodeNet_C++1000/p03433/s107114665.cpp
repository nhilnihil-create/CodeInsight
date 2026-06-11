#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int targetAmount, yen1;
  cin >> targetAmount >> yen1;
 
  // 500で割ったあまりを算出する
  int surplus = targetAmount % 500;
  
  // 割ったあまりより1円玉が多ければ支払える
  if (yen1 >= surplus) { cout << "Yes" << endl; }
  else { cout << "No" << endl; }
}