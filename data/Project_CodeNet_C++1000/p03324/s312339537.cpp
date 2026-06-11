#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  long long D, N;
  cin >> D >> N;
  cout << setprecision(9);
  if (N == 100){
    N += 1;
  }
  
  cout << pow(100, D) * N << endl;
}