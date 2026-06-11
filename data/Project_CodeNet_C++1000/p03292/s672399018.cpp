#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC103 A - Task Scheduling Problem
// 2020.06.12

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> A(3, 0);
  REP(i, 3){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int ans = A[2]-A[0];
  cout << ans << endl;
}