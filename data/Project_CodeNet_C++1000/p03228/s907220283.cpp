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
  ll A, B; cin >> A >> B;
  int K; cin >> K;
  REP(i, K){
    if(i%2 == 0){
      if(A%2 == 1) A--;
      A /= 2;
      B += A;
    }else{
      if(B%2 == 1) B--;
      B /= 2;
      A += B;
    }
  }
  cout << A << " " << B << endl;
}