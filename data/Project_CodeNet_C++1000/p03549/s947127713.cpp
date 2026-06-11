#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  cout << (1900 * M + 100 * (N - M)) * (1 << M) << endl;
  return 0;
}