#include <iostream>

int main(){
   int N, A, B;
   std::cin >> N >> A >> B;
   int sum2 = 0;
   for (int i=1; i<=N; i++){
      int N5 = i/10000;
      int N4 = (i-N5*10000)/1000;
      int N3 = (i-N5*10000-N4*1000)/100;
      int N2 = (i-N5*10000-N4*1000-N3*100)/10;
      int N1 = (i-N5*10000-N4*1000-N3*100)%10;
      int sum = N1+N2+N3+N4+N5;
      //std::cerr << sum << std::endl;
      if ((sum >= A) && (sum <= B)){
         sum2 = sum2 + i;
         //std::cerr << i << " " << sum2 << std::endl;
      }
   }
   std::cout << sum2 << std::endl;
}

