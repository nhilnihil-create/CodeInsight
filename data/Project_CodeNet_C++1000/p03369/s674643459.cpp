#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;

int main(){
  string s;
  cin >> s;
  int ans = 700;
  rep(i, 3){
    if (s[i] == 'o') ans += 100;
  }
  cout << ans << endl;
}

