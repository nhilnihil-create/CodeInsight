#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void dfs() {}

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  vector<int> cnt(N);
  for (int l = 0; l < N - 1; l++)
  {
    
    if (S[l] == 'A' && S[l + 1] == 'C')
    {
      cnt[l + 1]++;
    }
    if (l == 0)
    {
      continue;
    }
    cnt[l] += cnt[l - 1];
  }
  cnt[N - 1] += cnt[N - 2];

  while (Q--)
  {
    int l, r;
    cin >> l >> r;
    --l;--r;
    if (l == 0)
    {
      cout << cnt[r] << endl;
      continue;
    }
    
    cout << cnt[r] - cnt[l] << endl;
  }
  
  return 0;
}
