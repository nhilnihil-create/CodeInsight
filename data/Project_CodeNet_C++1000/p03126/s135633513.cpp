#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> food(m);
  
  REP(i,n){
    int k;
    cin >> k;
    REP(i,k){
      int a;
      cin >> a;
      --a;
      food[a]++;
    }
  }
  int cnt = 0;
  REP(i,m){
    //cout << food[i] << endl;
    if(food[i] == n) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
