#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S; cin >> S;
  int K; cin >> K;
  int N = S.size();
  set<string> res;
  REP(i, N){
    REP(j, min(K, N-i)){
      res.insert(S.substr(i, j+1));
    }
  }
  int cnt = 0;
  for(auto i : res){
    if(cnt == K-1){
      cout << i << endl;
      return 0;
    }
    cnt++;
  }
}