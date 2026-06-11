#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,29)-1;


int main() {
  int path[4]={};
  rep(i,3) {
    int a, b; cin >> a >> b; a--; b--;
    path[a]++; path[b]++;
  }
  string result = "YES";
  rep(i,4) if (path[i]==3) result = "NO";
  cout << result << endl;
  return 0;
}