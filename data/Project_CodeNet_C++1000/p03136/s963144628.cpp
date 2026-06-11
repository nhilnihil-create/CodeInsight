#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N;
int L[110];

int main(){
  cin >> N;
  rep(i, N) cin >> L[i];

  int sums = 0;
  rep(i, N) sums += L[i];

  sort(L, L+N);

  if (sums - L[N-1] > L[N-1]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
