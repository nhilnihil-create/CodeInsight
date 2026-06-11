#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  int N, K; cin >> N >> K;
  cout << ((N+1)/2 >= K ? "YES" : "NO") << endl;
}