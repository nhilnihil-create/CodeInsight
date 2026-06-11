#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, H;
  cin >> N >> H;
  long long a, b[N], A = 0, B = 0, answer = H;
  for (int i = 0; i < N; i++) {
    cin >> a >> b[i];
    A = max(A,a);
  }
  sort(b,b+N,greater<long long>());
  for (int i = 0; i < N; i++) {
    B += b[i];
    answer = min(answer,i+1+max(0ll,(long long)ceil((H-B)*1.0/A)));
  }
  cout << answer;
}