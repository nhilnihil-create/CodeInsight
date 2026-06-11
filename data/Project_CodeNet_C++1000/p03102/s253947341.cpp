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
  int n, m, c;
  cin >> n >> m >> c;
  int cnt = 0;
  int b[100];
  rep(i, m) cin >> b[i];
  for(int i = 0; i < n; i++){
    int tmp = 0;
    rep(i, m){
      int u; 
      cin >> u;
      tmp += u * b[i];
    }
    if(tmp > -c) cnt++;
  }
  cout << cnt <<endl;
}