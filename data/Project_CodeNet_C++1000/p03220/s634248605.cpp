#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,T,A;
  cin >> N >> T >> A;
  
  vector<int>H(N);
  vector<double>temp(N);
  vector<double>dis(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
    temp.at(i) = T - H.at(i)*0.006;
    if (A > temp.at(i)){
      dis.at(i) = A - temp.at(i);
    }
    else {
      dis.at(i) = temp.at(i) - A;
    }
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (dis.at(i) > dis.at(j)){
        break;
      }
      else if (j == N - 1){
        cout << i + 1 << endl;
        i = N;
        break;
      }
    }

  }
}

