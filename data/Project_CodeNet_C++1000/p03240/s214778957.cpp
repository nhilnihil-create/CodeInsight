#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const ll INF = 1001001001;
const ll MOD = 1e9 + 7;

int main(){
  int n;
  cin >> n;
  pair<int, pair<int, int>> p[100];
  rep(i, n){
    int x, y, h;
    cin >> x >> y >> h;
    p[i] = make_pair(h, P(x, y));
  }
  sort(p, p+n);
  reverse(p, p+n);
  for(int i = 0; i < 101; i++){
    for(int j = 0; j < 101; j++){
      int H = p[0].first + abs(p[0].second.first - i) + abs(p[0].second.second - j);
      bool flag = true;
      for(int k = 1; k < n; k++){
        if(max(H - abs(p[k].second.first - i) - abs(p[k].second.second - j), 0) != p[k].first){
          flag = false;
          break;
        }
      }
      if(flag){
        printf("%d %d %d\n", i, j, H);
      }
    }
  }
}