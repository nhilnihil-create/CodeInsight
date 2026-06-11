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

const int max_m = 15;
int n, m, ans = 0;
int k[max_m], s[max_m][max_m], p[max_m];

int main(){
    cin >> n >> m;
    rep(i, m){
        cin >> k[i];
        rep(j, k[i]){
            cin >> s[i][j];
        }
    }
    rep(i, m) cin >> p[i];

    for(int bit = 0; bit < (1 << n); bit++){
        bool flag = true;
        for(int i = 0; i < m; i++){
            int sw = 0;
            for(int j = 0; j < k[i]; j++){
                if(bit & (1 << (s[i][j] - 1))) sw++;
            }
            sw %= 2;
            if(p[i] != sw){
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }
    cout << ans << endl;
    return 0;
}