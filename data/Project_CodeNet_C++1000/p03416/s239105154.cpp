#include <bits/stdc++.h>
using namespace std;

int main() {
 int A,B;
 cin >> A >> B;
  
 int count = 0;
 
 for (int i = A; i <= B; i++) {
   int a1 = i % 10;
   int a10 = (i / 10) % 10;
   int a1000 = (i / 1000) % 10;
   int a10000 = i / 10000;
   
   if (a1 == a10000 && a10 == a1000) {
    count++;
   }
 }
  
  cout << count << endl;
}
