#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr int64_t Vmax= 3500;
  int64_t N;
  cin >> N;

  bool found= false;
  for(int64_t a=1; a <= Vmax; a++){
    for(int64_t b=1; b <= Vmax; b++){
      int64_t numer= N*a*b;
      int64_t denom= 4*a*b- N*(a+b);
      if(denom > 0 && numer % denom == 0){
        int64_t c= numer/ denom;
        if(c <= Vmax){
          cout << a <<" "<< b <<" "<< c << endl;
          found= true;
          break;
        }
      }
    }
    if(found){ break; }
  }
}