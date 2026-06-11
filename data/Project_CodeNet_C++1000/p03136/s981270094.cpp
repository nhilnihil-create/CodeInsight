#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC117 B - Polygon
// 2020.07.01

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  int maxL = 0;
  int sumL = 0;
  vector<int> L(N);
  REP(i, N){
    cin >> L[i];
    maxL = max(maxL, L[i]);
    sumL += L[i];
  }
  sumL -= maxL;
  if(maxL < sumL){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}