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
  int N; cin >> N;
  vector<string> S(N);
  map<string, int> mp;
  REP(i, N){
    cin >> S[i];
    mp[S[i]]++;
  }
  bool flag = true;
  REP(i, N-1){
    int tmp = S[i].size() - 1;
    if(S[i][tmp] != S[i+1][0]) flag = false;
  }
  for(auto i : mp){
    if(i.second > 1) flag = false;
  }
  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}