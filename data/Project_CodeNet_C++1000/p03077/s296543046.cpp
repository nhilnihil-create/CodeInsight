#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

ll my_ceil(ll a, ll b){
  return (a + b - 1) / b;
}

ll N, A, B, C, D, E;

int main(){
  cin >> N >> A >> B >> C >> D >> E;
  cout << 5 + (my_ceil(N, min({A, B, C, D, E})) - 1) << endl;
}
