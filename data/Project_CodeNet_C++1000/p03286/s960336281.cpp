

#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
   int N;
   cin >> N;
   string S = "";
   if( N == 0 ) S = "0";
   while (N != 0) {
     if(N > 0){
       if(N%2 == 1){
          S = "1" + S;
          N = 0 - N / 2;
       }
       else{
          S = "0" + S;
          N = 0 - N / 2;
       } 
     }
     else if(N < 0){
       N = 0 - N;
       if(N%2 == 1){
          S = "1" + S;
          N = N / 2 + 1;
       }
       else{
          S = "0" + S;
          N = N / 2;
       } 
     }
   }
   cout << S << endl;

}
