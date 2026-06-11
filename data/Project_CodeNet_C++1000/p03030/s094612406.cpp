#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;

int main() {
  int N;
  cin >> N;
  vector<pair<pair<string, int>, int>> p(N);
  rep(i,N){
    string S;
    int P;
    cin >> S >> P;
    p[i] = make_pair(make_pair(S, -P), i+1);
  }
  sort(p.begin(), p.end());
  rep(i,N) cout << p[i].second << endl; 
  return 0;
}
