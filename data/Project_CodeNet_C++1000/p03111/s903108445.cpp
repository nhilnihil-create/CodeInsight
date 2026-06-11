#include <bits/stdc++.h>
using namespace std;
long long INF = 10000000;
int main(){
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> l(N);
  for (int i = 0; i < N; i++){
    cin >> l[i];
  }
  int ans = INF;
  for (int i = 0; i < (1 << (N * 2)); i++){
    int a = 0;
    int b = 0;
    int c = 0;
    int tmp = 0;
    for (int j = 0; j < N; j++){
      if ((i >> (j * 2)) & 1){
        if ((i >> (j * 2 + 1)) & 1){
          if (a != 0){
            tmp += 10;
          }
          a += l[j];
        } else {
          if (b != 0){
            tmp += 10;
          }
          b += l[j];
        }
      } else {
        if ((i >> (j * 2 + 1)) & 1){
          if (c != 0){
            tmp += 10;
          }
          c += l[j];
        }
      }
    }
    if (a != 0 && b != 0 && c != 0){
      vector<int> L(3);
      L[0] = a;
      L[1] = b;
      L[2] = c;
      sort(L.begin(), L.end());
      tmp += abs(L[0] - C);
      tmp += abs(L[1] - B);
      tmp += abs(L[2] - A);
      ans = min(ans, tmp);
    }
  }
  cout << ans << endl;
}