#include <bits/stdc++.h>
using namespace std;

int main() {
 int A , N , Y;
 string S;
 cin >> N;
 A = 0;

 for ( int i = 0; i < N; i++){
   cin >> S;
   if ( S == "Y" ){
     A = A + 1;
   }
 }

 if ( A == 0 ){
   cout << "Three" << endl;
 }

 else{
   cout << "Four" << endl;
 }

}