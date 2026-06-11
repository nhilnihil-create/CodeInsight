#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,X,m;
  cin >> N >> X;
  int min=1000;
  int sum=0;
  for (int i=0; i < N; i++){
    cin >>m;
    if (m<min) min=m;
    sum = sum + m;
  }
  int ans = (X - sum)/min + N;
  cout << ans << endl;
}