#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, h, n, w;
  int a = n = h = w =1;
  cin >> N;
  for(h=1; h<=3500; h++){
    for(n = h; n<=3500; n++){
      if(4*h*n-N*(h+n)>0){
      if(N*h*n%(4*h*n-N*(h+n))==0){
        w = N*h*n/(4*h*n-N*(h+n));
        if(w!=0){
        int a =0;
        goto SKIP;
        }
      }
      }
    }
  }
  
  SKIP:
  
  cout << h << " " << n << " " << w <<endl;
        
}