#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int N, Q; string s;
vector<pair<char, char> > td;
bool Clb(int k){
  REP(i, Q){
    if(td[i].first == s[k-1]){
      k = (td[i].second == 'R') ? k + 1 : k - 1;
      if(k == 0) return true;
      if(k == N + 1) return false;
    }  
  }
  return false;
}

bool Cub(int k){
  REP(i, Q){
    if(td[i].first == s[k-1]){
      k = (td[i].second == 'R') ? k + 1 : k - 1;
      if(k == N + 1) return true;
      if(k == 0) return false;
    }  
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Q >> s;
  REP(i, Q){
    char t, d; cin >> t >> d;
    td.push_back({t, d});
  }
  int lb = 0, ub = N + 1;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(Clb(mid)) lb = mid;
    else ub = mid;
  }
  int ans1 = lb;
  lb = 0; ub = N + 1;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(Cub(mid)) ub = mid;
    else lb = mid;
  }
  int ans2 = ub;
  cout << ans2 - ans1 - 1 << endl;
}
