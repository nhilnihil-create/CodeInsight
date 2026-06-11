#include <iostream>
#include <iomanip>

const int MAX_N = 100;
double t[MAX_N], v[MAX_N];
double l[MAX_N], r[MAX_N];

double f(int index, double time){
   if(time<l[index]) return v[index] + l[index] - time;
   else if(time>r[index]) return v[index] + time - r[index];
   else return v[index];
}

int main(){
   int N;
   std::cin >> N;
   double tsum = 0;
   for(int i=0; i<N; ++i){
      std::cin >> t[i];
      l[i] = tsum;
      tsum += t[i];
      r[i] = tsum;
   }
   for(int i=0; i<N; ++i)
      std::cin >> v[i];

   double ans = 0;
   for(int i=0; i*0.5+0.5<=tsum; ++i){
      double min = 0.25 * (i*0.5 + i*0.5+0.5);
      for(int j=0; j<N; ++j){
	 double area = 0.25 * (f(j, i*0.5) + f(j, i*0.5+0.5));
	 min = std::min(min, area);
      }
      min = std::min(min, 0.25*(r[N-1]-i*0.5 + r[N-1]-i*0.5-0.5));
      ans += min;
   }

   printf("%.4f\n",ans);
   return 0;
}
