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
  int n;
  cin >> n;
  vector<int> c(n-1), s(n-1), f(n-1);
  rep(i, n-1) cin >> c[i] >> s[i] >> f[i];
  rep(i, n-1){
    int j = i;
    int t = 0;
    t += s[i] + c[i];
    j++;
    while (j < n-1){
      if (s[j] <= t && t % f[j] == 0){
        t += c[j];
        j++;
      }else {
        t++;
      }
    }
    cout << t << endl;
  }
  cout << 0 << endl;
}