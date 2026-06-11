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
  int H, W, D; cin >> H >> W >> D;
  vector<pair<int, int> > A(H*W, pair<int, int>());
  REP(i, H){
    REP(j, W){
      int tmp; cin >> tmp; tmp--;
      A[tmp] = {i+1, j+1};
    }
  }
  vector<int> AA(H*W, 0);
  REP(i, D){
    for(int j = i; j < H*W; j += D){
      if(j >= D){
        AA[j] = AA[j-D] + abs(A[j].first-A[j-D].first)+abs(A[j].second-A[j-D].second);
      }
    }
  }
  int Q; cin >> Q;
  vector<int> L(Q);
  vector<int> R(Q);
  REP(i, Q){
    cin >> L[i] >> R[i]; L[i]--; R[i]--;
  }
  REP(i, Q){
    cout << AA[R[i]] - AA[L[i]] << endl;
  }
}