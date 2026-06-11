#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC105 A - AtCoder Crackers

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K; cin >> N >> K;
  if(N%K == 0){
    cout << 0 << endl;
  }else{
    cout << 1 << endl;
  }
}