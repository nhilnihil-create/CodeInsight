#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
vector<int> P[N];
map<pii, bool> cor;

int main(){
  fastIO;
  int n, m, q;
  cin >> n >> m >> q;
  int x, y;
  for(int i = 0 ; i < q; i ++ ){
    cin >> x >> y;
    cor[mp(y,x)] = true;
    P[y].push_back(x);
  }
  for(int i = 1; i <= m ; i ++ )
    P[i].push_back(n + 1);
  for(int i = 1; i <= m ; i ++ )
    sort(P[i].begin(), P[i].end());
  int low = P[1][0];
  int pos = 2;
  int res = P[1][0] - 1;
  int idx;
  for(int i = 2; i <= m ; i ++ ){
    while(pos < low && cor[mp(i, pos)]){
      pos ++ ;
    }
    if(pos >= low) break;
    idx = 0;
    while(P[i][idx] < pos)
      ++idx;
    res = min(res, P[i][idx] - 1);
    pos ++ ;
  }
  cout << res;
  return 0;
}
