#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  return b != 0 ? gcd(b, a % b) : a;
}

int N;
ll A[100010];

int main(){
  cin >> N;
  rep(i, N) cin >> A[i];

  int g;
  g = gcd(A[0], A[1]);
  rep(i, N-2) g = gcd(g, A[i+2]);

  cout << g << endl;
}
