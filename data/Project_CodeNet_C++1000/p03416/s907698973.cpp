#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int count = 0;
  int x = A;
 for (int i = 0; i < (B-A+1); i++) {
   int a = x/10000; // 10000
   int e = x%10; // 1
   int b = x/1000-x/10000*10; // 1000
   int d = x/10-x/100*10; // 10
   if((a == e) && (b == d))
     count ++;
   x ++;
 }
  cout << count << endl;
}