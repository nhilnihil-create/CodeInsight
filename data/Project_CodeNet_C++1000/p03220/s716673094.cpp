#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T;
int A;
int H[1010];
double aveT[1010];
double Tdif[1010];

int main(){

 cin >> N >> T >> A ;
 for(int i=0; i<N; i++)cin >> H[i];
 for(int i=0; i<N; i++)aveT[i]=T-H[i]*0.006;

  
 
  for(int i=0; i<N; i++) Tdif[i]=abs(aveT[i]-A);
  double *mn=min_element(Tdif,Tdif+N);
 
  printf("%d",mn-Tdif+1);
  
}