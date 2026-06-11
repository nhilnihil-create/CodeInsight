#include <bits/stdc++.h>
using namespace std;

int main(void){
    
   int D,N;
   cin >> D >> N;
  
   if(D == 0){
       if(N == 100) cout << 101 << endl;
       else cout << N << endl;
   }
   else if(D == 1){
       if(N == 100)cout << 100 * N + 100<< endl;
       else cout << 100 * N << endl;
   }
   else{
       if(N == 100)cout << 10000 * N  + 10000<< endl;
       else cout << 10000 * N << endl;
   }
}