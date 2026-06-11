#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n,m;cin>>n>>m;
  ll d = m / n;
  while (d > 1 && m % d != 0) d--;
  cout<<d;
}
