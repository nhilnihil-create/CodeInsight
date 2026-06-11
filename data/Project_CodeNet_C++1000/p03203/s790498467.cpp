#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

vector<int> v[200005];

int main(){
  int H, W, N;
  cin >> H >> W >> N;

  rep(i,N){
    int X, Y;
    cin >> X >> Y;
    v[X].push_back(Y);
  }

  int ret = H;
  int range = 1;
  REP(i,2,H+1){
    sort(ALLOF(v[i]));
    if(v[i].size() == 0){
      range++;
    }else{
      if(v[i][0] <= range){
        ret = min(ret, i-1);
      }else if(v[i][0] == range+1){
        ;
      }else{
        range++;
      }
    }
  }

  cout << ret << endl;
  
  return 0;
}
