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
  vector<int> a(3);
  rep(i, 3) cin >> a[i];
  sort(ALL(a));
  if (a[0] != a[1]) cout << a[0] << endl;
  else cout << a[2] << endl;
}