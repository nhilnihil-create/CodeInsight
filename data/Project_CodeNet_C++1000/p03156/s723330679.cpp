#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  int N, A, B; cin >> N >> A >> B;
  int a=0, b=0, c=0;
  REP(i, N) {
    int p; cin >> p;
    if (p <= A) a++;
    else if (A < p && p <= B) b++;
    else c++;
  }
  cout << min({a, b, c}) << endl;
}