#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int main() {
  int A, B;
  cin >> A >> B;
  if(A % 2 == 1 && B % 2 == 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}