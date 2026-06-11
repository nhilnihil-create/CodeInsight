#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
   int N;
   cin >> N;
   string b = "No";
   rep(i,26){
     rep(j,15){
       if( N == i*4 + j*7){
         b = "Yes";
         break;
       }
     }
   }
   cout << b << endl;
   return 0;
}
