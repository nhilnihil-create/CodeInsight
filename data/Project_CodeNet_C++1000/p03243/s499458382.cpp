#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int N;
  cin >> N;

  while (!(N % 10 == (N%100)/10 && N % 10 == N/100)) {
    N++;
  }
  cout << N << endl;
  return 0;
}
