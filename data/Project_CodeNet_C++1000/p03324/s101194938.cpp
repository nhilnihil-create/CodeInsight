using namespace std;
    #include <iostream>
    #include <math.h>
    int main(){
      int D, N, fact;
      cin >> D >> N;
      if ( D >= 0 && D <= 2){
        if( N <= 99 && N >= 1 )
      	  fact = pow(100, D) * N;
        else
          fact = pow(100, D) * 101;
      cout << fact << endl;
      }
      return(0);
    } 