#include <bits/stdc++.h>
using namespace std;

int main() {
   int A,B,K;
   cin >> A >> B >> K;
   int count=0;
   int total=0;
   for (int i=1; i<=A; i++) {
       if (A%i==0 && B%i==0) total++;
   }
   for (int i=1; ; i++) {
       if (A%i==0 && B%i==0) count++;
       if (count==total-K+1) {
           cout << i << endl;break;
       }
   }
}