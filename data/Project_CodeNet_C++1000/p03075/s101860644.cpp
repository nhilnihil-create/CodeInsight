#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main(void) {
   int a, b, c, d, e, k;
   cin >> a >> b >> c >> d >> e >> k;
   if(abs(a - b) <= k && abs(a - c) <= k && abs(a - d) <= k && abs(a - e) <= k){
       if(abs(b - c) <= k && abs(b - d) <= k && abs(b - e) <= k){
           if(abs(c - d) <= k && abs(c - e) <= k){
               if(abs(d - e) <= k){
                   cout << "Yay!" << endl;
               }else{
                   cout << ":(" << endl;
               }
           }else{
               cout << ":(" << endl;
           }
       }else{
           cout << ":(" << endl;
       }
   }else{
       cout << ":(" << endl;
   }
    return 0;
}
