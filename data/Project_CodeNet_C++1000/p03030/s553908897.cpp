#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int N;
  cin >> N;

  map<string, vector<P>> sp;
  rep(i,N) {
    string S;
    int P;
    cin >> S >> P;
    sp[S].push_back(make_pair(P, i+1));
  }

  for(auto d: sp) {
    auto v = d.second;
    sort(v.rbegin(), v.rend());
    for(auto p: v) cout << p.second << endl;
  }

  return 0;
}
