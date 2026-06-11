#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K, a=1, i=0;
  cin >> N >> K;
  
  for (i; a<K && i<N; i++){
    a *= 2;
  }
  for (i; i<N; i++){
    a += K;
  }
  
  cout << a << endl;
}