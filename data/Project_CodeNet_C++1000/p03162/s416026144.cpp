#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() { 
    ll a[100010][3]={0};
    ll dp[100010][3]={0};
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++){
      for (int j = 0; j<3; j++){
        cin >> a[i][j];
      }
    }

    for(int i = 0; i < N; i++){
      for (int j = 0; j < 3; j++){
        for (int k = 0; k<3; k++){
            if(j!=k){
                chmax(dp[i + 1][j], dp[i][k] + a[i][j]);
            }
        }
      }
    }
    ll maxx = 0;
    for(int i = 0; i < 3; i++){
      maxx = max(maxx, dp[N][i]);
    }
    cout << maxx << endl;
    return 0;
}