#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K = 0;
  cin >> N >> K;
  if(N%2 == 1){
    N = N + 1;
  }
  N = N/2;
  if(N >= K){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}