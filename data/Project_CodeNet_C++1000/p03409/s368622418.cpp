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
  vector<P> a(n), b(n);
  rep(i, n) cin >> a[i].first >> a[i].second;
  rep(i, n) cin >> b[i].first >> b[i].second;
  sort(ALL(a));
  sort(ALL(b));
  int ans = 0;
  rep(i, n){
    int maxv = -1, num = -1;
    rep(j, a.size()){
      if (a[j].first < b[i].first && a[j].second < b[i].second){
        if (a[j].second > maxv){
          num = j;
          maxv = a[j].second;
        }
      }
    }
    if (maxv != -1){
      a.erase(a.begin() + num);
      ans++;
    }
  }
  cout << ans << endl;
}