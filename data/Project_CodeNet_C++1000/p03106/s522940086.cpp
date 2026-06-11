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

int a, b, k;
set<int, greater<int>> st;

int main(){
    cin >> a >> b >> k;
    int n = min(a, b);
    rep2(i, 1, n+1){
        if(a % i == 0 && b % i == 0) st.insert(i);
    }
    auto iter = st.begin();
    rep(i, k-1) iter++;
    cout << *iter << endl;
    return 0;
}