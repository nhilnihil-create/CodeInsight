#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  ll coc[2];
  int K;
  cin >> coc[0] >> coc[1] >> K;
  for (int i = 0; i < K; i ++) {
    int j = i % 2;
    int k = (j + 1) % 2;
    coc[j] /= 2;
    coc[k] += coc[j];
  }
  cout << coc[0] << ' ' << coc[1] << endl;
}
