#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N; cin >> N;
  for(long long h = 1; h <= 3500; h++){
    for(long long n =1; n <=3500; n++){
      if(4*h*n -N*(h+n) == 0)continue;
      if((N*h*n)% (4*h*n -N * (h+n)) != 0) continue; 
      long long w = (N*h*n)/(4*h*n -N*(h+n));
      if(w > 0){
        cout << h << " " << n << " " << w << endl;
        return 0;
      }
    }
  }      
      
}