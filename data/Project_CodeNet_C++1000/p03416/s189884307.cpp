#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  int digit_10000, digit_1000,digit_100, digit_10, digit_1;
  int count = 0;
  // 変数aで入力を受け取る
  cin >> a >>b;
  
 while (a <= b){
   digit_10000 = a/10000;
   digit_1000 = (a - 10000 * digit_10000) /1000;
   digit_100 =  (a - 10000 * digit_10000 - 1000 * digit_1000) / 100 ;
   digit_10 = (a - 10000 * digit_10000 - 1000 * digit_1000 - 100 * digit_100) / 10 ;
   digit_1 = (a - 10000 * digit_10000 - 1000 * digit_1000 - 100 * digit_100 - 10 * digit_10) / 1 ;
  
   if ( digit_10000 == digit_1 && digit_1000 == digit_10){
     count++;}
   
   a++;
 }
   
cout << count << endl;
}