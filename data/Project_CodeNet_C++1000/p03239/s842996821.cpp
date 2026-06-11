#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N, T;
int c, t;
vector<pair<int, int>> X;

int main(){
  cin >> N >> T;
  rep(i, N){
    cin >> c >> t;
    X.push_back(make_pair(c, t));
  }

  sort(X.begin(), X.end());

  bool flag = true;
  rep(i, N){
    if (X[i].second <= T){
      cout << X[i].first << endl;
      flag = false;
      break;
    }
  }

  if (flag) cout << "TLE" << endl;
}
