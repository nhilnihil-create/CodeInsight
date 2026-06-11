#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  int N, K;
  cin >> N >> K;
  
  double p = 0;
  
  for(int i=1; i<=N; i++){
    double tmp = 1.0/N;
    
    int now = i;
    while(now<K){
      now *= 2;
      tmp /= 2;
    }
    
    p += tmp;
  
  }
  
  //cout << p << endl;
  printf("%.12lf\n", p);
  return 0;
}