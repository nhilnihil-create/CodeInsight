#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int count = 0;
  
 for (int i = 0; i < N; i++) {
   int A;
   cin >> A;   
   int subcount = 0;
   for (int j = 0; ; j++){
     if (A % 2 == 1)
       break;
     else{
       subcount ++;
       A /= 2;
     }
   }
     if(i == 0)
       count = subcount;
     else if(count > subcount){
     count = subcount;
     }
 }
   cout << count << endl;
}