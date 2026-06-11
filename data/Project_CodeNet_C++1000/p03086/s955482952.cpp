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

char text[4] = {'A', 'G', 'C', 'T'};
int n;
string s;

int main(){
    getline(cin, s);
    n = s.length();
    int cnt=0, ans=-1;
    rep(i, n){
        bool flag = true;
        rep(j, 4){
            if(s[i] == text[j]){
                cnt++;
                flag = true;
                break;
            } else {
                flag = false;
            }
        }
        if(!flag){
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);
    cout << ans << endl;
    return 0;
}