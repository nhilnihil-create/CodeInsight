#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a1(n), a2(n, 0);//添え字ずれるよ
  cin >> a1[0];
  for (int i = 1; i < n; i++) {
    int a1i;
    cin >> a1i;
    a1[i] = a1[i-1] + a1i;
  }
  for (int i = 0; i < n; i++) {
    int a2i;
    cin >> a2i;
    for (int j = 0; j <= i; j++) a2[j] += a2i;
  }
  int candy = 0;
  for (int i = 0; i < n; i++) {//iで↓移動
    int sum = a1[i] + a2[i];
    candy = max(candy, sum);
  }
  cout << candy;
}