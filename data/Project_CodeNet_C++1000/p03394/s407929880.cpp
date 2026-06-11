#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {

    int N;
    cin >> N;
    
    if (N <= 5) {
      int a[5] = {2, 5, 63, 20, 30};
      rep(i,N) {
        cout << a[i];
        if (i < N - 1) cout << " ";
        else cout << endl;
      }
      return 0;
    }

    set<int> s;
    int now = 0;
    int sum = 0;
    while (s.size() < N) {
      now++;
      if (now % 6 == 1 || now % 6 == 5) continue;
      s.insert(now);
      sum += now;
    }

    if (sum % 6 == 2) {
      s.erase(8);
      while (++now % 6 != 0) {}
      s.insert(now);
    } else if (sum % 6 == 3) {
      s.erase(9);
      while (++now % 6 != 0) {}
      s.insert(now);
    } else if (sum % 6 == 5) {
      s.erase(9);
      while (++now % 6 != 4) {}
      s.insert(now);
    }

    for (int k : s) {
      if (k < *(s.rbegin())) cout << k << " ";
      else cout << k << endl;
    }
    
    return 0;
}