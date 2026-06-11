#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  cout << min(A*N, B) << endl;

  return 0;
}