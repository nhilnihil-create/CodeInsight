#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0LL)
typedef long long unsigned int ll;
const long mod = 1e9 + 7;

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  if (N == 1) {
    cout << "Hello World" << endl;
  } else {
    int A, B;
    cin >> A;
    cin >> B;
    cout << A + B << endl;
  }

  return 0;
}
