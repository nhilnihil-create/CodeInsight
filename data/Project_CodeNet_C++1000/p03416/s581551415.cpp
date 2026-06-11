#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int count = 0;
 for (int i = A; i <=B; i++) {
   int a = i/10000; // 10000
   int e = i%10; // 1
   int b = i/1000-i/10000*10; // 1000
   int d = i/10-i/100*10; // 10
   if((a == e) && (b == d)){
     count ++;
   }
 }
  cout << count << endl;
}
