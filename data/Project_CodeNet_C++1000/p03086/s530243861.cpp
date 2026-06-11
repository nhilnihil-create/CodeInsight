
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<numeric>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main () {
  int n,cnt = 0,cnt2 = 0;
  string s;
  cin >> s;
  n = s.size();
  vector<int> m(n);
  for (int i = 0; i < n; i++){
    if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'){
      for (int j = 0; i < n; i++){
        if (s[i] != 'A' && s[i] != 'C' && s[i] != 'G' && s[i] != 'T'){
          break;
        }
        cnt++;
      }
    }
    if (cnt > cnt2){
      cnt2 = cnt;
    }
    cnt = 0;
  }
  cout << cnt2 << '\n';
  return 0;
}