#include <iostream>
using namespace std;
double abs(double x){
  if(x < 0)return 0.0-x;
  else return x;
}
int main(){
  int N,n;
  double m,t,S=0,M[110];
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> M[i];
    S += M[i];
  }
  m = S/(double)N;
  for(int i=0;i<N;i++){
    t = abs(m-M[i]);
    if(S > t){
      n = i;
      S = t;
    }
  }
  cout << n;
}
