#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M, X, to0 = 0, toN = 0;
  cin >> N >> M >> X;
  vector<int> v(M);
  for (int i = 0; i < M; i++){
    cin >>v.at(i);
    if (v.at(i) < X) to0++;
    else toN++;
  }
  cout << min(to0, toN);
}