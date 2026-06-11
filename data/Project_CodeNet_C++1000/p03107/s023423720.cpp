#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;
  int N = S.length();
  int cnt[2];
  cnt[0] = cnt[1] = 0;

  for (int i = 0; i < N; i++)
  {
    if (S[i] == '0')
    {
      cnt[0]++;
    } else
    {
      cnt[1]++;
    } 
  }
  cout << min(cnt[0], cnt[1]) * 2 <<endl;
  return 0;
}
