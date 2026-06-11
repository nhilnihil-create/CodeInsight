#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N, K; cin >> N >> K;
  long long a = pow(N/K, 3), b = pow(2*N/K - N/K, 3);
  if(K%2 != 0){
    cout << a << endl;
  }
  else{
    cout << a + b << endl;
  }
}