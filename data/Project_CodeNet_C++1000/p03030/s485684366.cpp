#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

const int M = 1000005;

int main() {
  int n;
  cin >> n;
  vector<tuple<string, int, int>> v;
  rep(i, n){
    string s;
    int tmp;
    cin >> s >> tmp;
    v.push_back(make_tuple(s, tmp*(-1), i+1));
  }

  sort(v.begin(), v.end());

  rep(i, n){
    cout << get<2>(v[i]) << endl;
  }

  return 0;
}