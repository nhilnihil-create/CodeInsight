#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  double sum = 0;
  for (int i = 0; i < N; i++){
    cin >> a[i];
    sum += a[i];
    a[i] *= N;
  }
  int m = 1000000;
  int c = 0;
  for (int i = 0; i < N; i++){
    if (abs(sum - a[i]) < m){
      m = abs(sum - a[i]);
      c = i;
    }
  }
  cout << c;
}