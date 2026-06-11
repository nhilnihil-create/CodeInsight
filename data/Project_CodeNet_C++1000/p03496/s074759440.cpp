#include <iostream>

const int INF = 1000001;

int main(){
   int N;
   std::cin >> N;
   int a[N];
   int max = -INF;
   int min = INF;
   int mindex, mandex;
   for(int i=0; i<N; ++i){
      std::cin >> a[i];
      if(max<a[i]){
	 max = a[i];
	 mandex = i+1;
      }
      if(min>a[i]){
	 min = a[i];
	 mindex = i+1;
      }
   }
   if(max==min){
      std::cout << 0 << std::endl;
      return 0;
   }else{	
      std::cout << 2*N-1 << std::endl;
   }
   for(int i=0; i<N; ++i){
      if(abs(max)>abs(min)){
	 a[i] += max;
	 std::cout << mandex << ' ' << i+1 << std::endl;
      }else{
	 a[i] += min;
	 std::cout << mindex << ' ' << i+1 << std::endl;
      }
   }

   if(abs(max)>abs(min)){
      for(int i=0; i<N-1; ++i){
	 std::cout << i+1 << ' ' << i+2 << std::endl;
	 a[i+1] += a[i];
      }
   }else{
      for(int i=N-2; i>=0; --i){
	 std::cout << i+2 << ' ' << i+1 << std::endl;
	 a[i] += a[i+1];
      }
   }


   return 0;
}
