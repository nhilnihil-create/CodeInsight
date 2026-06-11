#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
#define all(x) (x).begin(),(x).end()

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a[3];
  for(int i=0; i<n; i++){
    for(int j=0; j<3; j++){
      ll num; cin >> num;
      a[j].push_back(num);
    }
  }
  ll res = 0;
  for(int bit=0; bit<(1<<3); bit++){
    //各条件ごとのケーキの貢献度を調べ、貪欲に食べる
    vector<ll> score;
    for(int i=0; i<n; i++){
      ll num = 0;
      for(int j=0; j<3; j++){
        if(bit & (1<<j)) num += a[j][i];
        else num -= a[j][i];
      }
      score.push_back(num);
    }
    sort(all(score), greater<ll>());
    ll sum = 0;
    for(int i=0; i<m; i++){
      sum += score[i];
    }
    res = max(res, sum);
  }
    cout << res << ln;
  }
