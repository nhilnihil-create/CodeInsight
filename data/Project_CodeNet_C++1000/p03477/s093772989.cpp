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
  int A, B, C, D; cin >> A >> B >> C >> D;
  if(A+B > C+D){
    cout << "Left" << endl;
  }else if(A+B == C+D){
    cout << "Balanced" << endl;
  }else{
    cout << "Right" << endl;
  }
}