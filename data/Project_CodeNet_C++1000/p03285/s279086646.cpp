#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC105 B - Cakes and Donuts
// 2020.06.09

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  REP(i, 26){
    REP(j, 16){
      if(i*4 + j*7 == N){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}