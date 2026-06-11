#include <bits/stdc++.h>
using namespace std;

int power(int n, int K){
  int p = 0;
  int num = n;
  while(num<K){
    p++;
    num*=2;
  }

  return p;

}

int main(){
  
  int N,K;
  cin >> N >> K;
  double Ans = 0;

  for(int i = 1; i <= N; i++){
    int x = power(i,K);
    double mom = pow(2,x);
    Ans += 1/(N*mom);
  }
  
  cout << setprecision(12);

  cout << Ans << endl;

}
