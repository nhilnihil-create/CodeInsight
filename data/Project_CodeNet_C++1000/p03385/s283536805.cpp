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
  bool oka = false;
  bool okb = false;
  bool okc = false;

  rep(i, 3){
    if (s[i] == 'a') oka = true;
    else if (s[i] == 'b') okb = true;
    else if (s[i] == 'c') okc = true;
  }

  if (oka && okb && okc) cout << "Yes\n";
  else cout << "No\n";
}

