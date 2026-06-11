#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(double i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	double N,K,sum = 0;
  cin >> N >> K;
  froop1(1,N+1){
   double present = i,per = 1;
    while(present < K){
      per *= 0.5;
      present *= 2;
    }
    per *= (1 / N);
    sum += per;
  }
	printf("%.12f\n",sum);
return 0;
}