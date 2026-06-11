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

const int max_n = 110, INF = 1e16;
int n;
bool f[max_n][10];
int p[max_n][10];
long long ans = -INF;

int main(){
    cin >> n;
    rep(i, n){
        rep(j, 10) cin >> f[i][j];
    }
    rep(i, n) rep(c, 11) cin >> p[i][c];

    for(int bit = 1; bit < (1 << 10); bit++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            int tmp = 0;
            for(int j = 0; j < 10; j++){
                if(f[i][j] == true && ((bit >> j) & 1) == 1) tmp++; 
            }
            sum += p[i][tmp];
        }
        if(ans < sum) ans = sum;
    }
    cout << ans << endl;
    return 0;
}