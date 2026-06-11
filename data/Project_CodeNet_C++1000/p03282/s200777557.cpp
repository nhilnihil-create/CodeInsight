#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
   string S;
   ll K;
   int b = 0;
   cin >> S >> K;
   int N[S.size()];
   rep(i, S.size()){
     N[i] = (int)(S[i] - '0');
   }
   rep(i, S.size()){
     if(N[i] == 1){
       K--;
     }else{
       b = N[i];
       break;
     }
     if(K == 0){
       b = 1;
       break;
     }
   }
   cout << b << endl;
   return 0;
}
