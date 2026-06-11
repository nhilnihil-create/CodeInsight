#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  int ma = 0;
  int sum = 0;
  for (int i = 0; i < N; i ++) {
    int a;
    cin >> a;
    if (ma < a) {
      sum += ma;
      ma = a;
    }
    else sum += a;
  }
  cout << (ma >= sum ? "No" : "Yes") << endl;
}
