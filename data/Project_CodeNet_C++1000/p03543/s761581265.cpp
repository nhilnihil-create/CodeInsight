#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, N_1000, N_100, N_10, N_1;
  cin >> N;

  N_1000 = N / 1000;
  N_100 = (N - 1000 * N_1000) / 100;
  N_10 = (N - 1000 * N_1000 - 100 * N_100) / 10;
  N_1 = N - 1000 * N_1000 - 100 * N_100 - 10 * N_10;

  if (N_1000 == N_100 && N_100 == N_10) {
    cout << "Yes" << endl;
  }
  else if (N_100 == N_10 && N_10 == N_1){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}