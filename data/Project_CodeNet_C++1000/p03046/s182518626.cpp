#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int M, K; cin >> M >> K;
  if(M == 0){
    if(K == 0){
      cout << 0 << " " << 0 << endl;
      return 0;
    }else{
      cout << -1 << endl;
      return 0;
    }
  }else if(M == 1){
    if(K == 0){
      cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
      return 0;
    }else{
      cout << -1 << endl;
      return 0;
    }    
  }else if(K >= pow(2, M)){
    cout << -1 << endl;
    return 0;
  }else{
    REP(i, pow(2, M)){
      if(i != K){
        cout << i << " ";
      }
    }
    cout << K << " ";
    for(int i = pow(2, M)-1; i >= 0; i--){
      if(i != K){
        cout << i << " ";
      }
    }
    cout << K << endl;
  }
}