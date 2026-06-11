#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int K;
  cin >> N >> K;
  int n;
  n = 1;
  for(int i=0; i < N; i++){
  int a;
  a = 2 * n;
  int b;
  b = n + K;
  if (a < b){
  n = a;
  }else{
    n = b;
  }
  }
  cout << n << endl;
}