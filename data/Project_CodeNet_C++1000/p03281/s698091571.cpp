#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;

int enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    return res.size();
}

int main() {
  int n; cin >> n;
  int cnt = 0;
  for (int i = 1; i <= n; i+=2) {
    int num = enum_divisors(i);
    if (num == 8) cnt++;
  }
  cout << cnt << endl;
}
