#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0;
  for(int i=0; i<N; i++){
    int A;
    cin >> A;
    sum += A;
  }
  cout << sum-N << endl;
}
