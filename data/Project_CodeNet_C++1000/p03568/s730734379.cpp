#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int fal=1, all=1;
  rep(i,n) {
    int x;
    cin >> x;
    if(x%2==0) fal *= 2;
  }
  rep(i,n) all *= 3;
  cout << all-fal << endl;
}
