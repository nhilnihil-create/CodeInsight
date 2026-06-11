#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int N,K;
  int total = 1;
  cin >> N >> K;
  rep(i, N) {
    if(total <= K){
      total += total;
    }else{
      total += K;
    }
  }
  cout << total;
}