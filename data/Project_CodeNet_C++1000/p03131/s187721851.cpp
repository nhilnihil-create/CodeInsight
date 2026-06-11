#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  ll K, A, B;
  cin >> K >> A >> B;
  if (A + 1 >= B || A >= K) {
    cout << K + 1 << endl;
    return 0;
  }
  ll dis = B - A;
  K -= (A - 1);
  cout << A + (dis * (K / 2)) + (K % 2) << endl;
}