#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// Tenka1 Programmer Bginner Contest A - Measure

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;  cin >> S;
  int N = S.size();
  if(N == 2){
    cout << S << endl;
  }else{
    REP(i, 3){
      cout << S[2-i];
    }
    cout << endl;
  }
}