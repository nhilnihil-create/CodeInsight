#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a(4);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  sort(a.begin(), a.end());
  int x = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
  cout << (x == 1479 ? "YES" : "NO");
}