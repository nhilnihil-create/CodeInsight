#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

int main() {
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  int m = max(max(a,b),c);
  cout << a + b + c - m + (m * (1 << k));;
}
