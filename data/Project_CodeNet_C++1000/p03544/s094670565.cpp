#include <bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin >> N;
  long long D[N + 1];
  D[0] = 2;
  D[1] = 1;
  for(int i = 2; i < N + 1; i++){
    D[i] = D[i - 1] + D[i - 2];
  }
  cout << D[N] << endl;
  return 0;
}