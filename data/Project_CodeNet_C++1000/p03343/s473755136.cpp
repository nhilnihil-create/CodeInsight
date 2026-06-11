#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

int solve(int Y, const vector<int>& v, int K, int Q){
  vector<vector<int>> w;
  vector<int> tmp;
  rep(i,v.size()){
    if(v[i] >= Y){
      tmp.push_back(v[i]);
    }else{
      if(tmp.size() > 0) w.push_back(tmp);
      tmp.clear();
    }
  }
  if(tmp.size() > 0) w.push_back(tmp);

  vector<int> ww;
  rep(i,w.size()){
    if(w[i].size() >= K){
      sort(ALLOF(w[i]));
      rep(j,w[i].size()-K+1){
        ww.push_back(w[i][j]);
      }
    }
  }

  if(ww.size() < Q) return 1000000005;
  
  sort(ALLOF(ww));
  
  return ww[Q-1] - ww[0];
}

int main(){
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> v;
  rep(i,N){
    int a;
    cin >> a;
    v.push_back(a);
  }

  int ret = 1000000005;
  rep(i,N){
    int Y = v[i];
    ret = min(ret, solve(Y, v, K, Q));
  }

  cout << ret << endl;
  
  return 0;
}
