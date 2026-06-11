#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  int N, A, B; cin>>N>>A>>B;

  while (true) {
    if (A+1 != B) {
      A ++;
    } else {
      cout << "Borys" << endl;
      return 0;
    }

    if (B-1 != A) {
      B --;
    } else {
      cout << "Alice" << endl;
      return 0;
    }
  }
  return 0;
}