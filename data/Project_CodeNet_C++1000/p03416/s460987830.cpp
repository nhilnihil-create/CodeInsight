#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b;
  cin >> a >> b;
  int cnt = 0;
  for(int i = a; i <= b; i++) {
    int l1 = i % 10;
    int l2 = i / 10 % 10;
    int f1 = i / 10000 % 10;
    int f2 = i / 1000 % 10;
    if(l1 == f1 && l2 == f2) cnt++;
  }
  cout << cnt << endl;
  return 0;
}