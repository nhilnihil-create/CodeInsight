#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, K, i, x;
  cin >> N >> K;
  i = 0;
  x = 1;
  while (i < N && x * 2 < x + K){
    x *= 2;
    i++;
  }
  if(i < N) x += K * (N - i);
  
  cout << x << endl;

}