#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main() {
  int N;
  cin >> N;

  pair<pair<string, int>, int> p[110];
  
  rep(i , N)
  {
    string s;
    int po;
    cin >> s >> po;
    p[i] = make_pair(make_pair(s, -po), i);
  }
  //sort(p.begin(), p.end());
  sort(p, p+N);
  rep(i , N)
  {
    cout << p[i].second+1 << endl;
  }
}