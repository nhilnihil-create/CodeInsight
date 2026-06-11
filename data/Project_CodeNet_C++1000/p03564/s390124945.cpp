#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,K,num;
  cin >> N;
  cin >> K;
  num = 1;
  
  rep(i,N){
  
  if (num < K)
    num *= 2;
  else
    num += K;
  }
  cout << num << endl;
}
