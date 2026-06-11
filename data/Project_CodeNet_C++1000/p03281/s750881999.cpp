#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

int n, ans=0;

int main(){
    cin >> n;
    rep2(k, 1, n+1){
        int cnt = 1;
        rep2(i, 1, n/2+1){
            if(k % i == 0) cnt++;
        }
        if(cnt == 8 && k % 2 != 0){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}