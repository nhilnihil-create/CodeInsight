#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using ll = long long;
using psi = pair<string, int>;
using psii = pair<psi,int>;

int main() {
  int N;
  cin >> N;
  vector<psii> p(N);
  rep(i,N) {
    cin >> p[i].first.first >> p[i].first.second;
    p[i].first.second *= -1;
    p[i].second = i+1;
  }
  sort(p.begin(), p.end());
  rep(i,N) {
    cout << p[i].second << endl;
  }
}