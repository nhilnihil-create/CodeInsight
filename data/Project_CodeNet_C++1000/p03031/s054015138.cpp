//#define _GLIBCXX_DEBUG//実行時、何も出なかったらこれを使う
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<numeric>
#include<climits>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }

int dy[] = {1,0,-1,0}; //次に行くところ
int dx[] = {0,1,0,-1}; //上に同じ

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m,cnt1 = 0,cnt2 = 0,cnt3 = 0;
  cin >> n >> m;
  vector<int> k(m),p(m),a;
  vector<vector<int>> s(m);
  for (int i = 0; i < m; i++){
    cin >> k[i];
    s[i].resize(k[i]);
    for (int j = 0; j < k[i]; j++){
      cin >> s[i][j];
    } 
  }

  for (int i = 0; i < m; i++){
    cin >> p[i];
  }
  
  for (int bit = 0; bit < 1 << n; bit++){
    cnt2 = 0;
    for (int i = 0; i < m; i++){
      cnt1 = 0;
      for (int j = 0; j < k[i]; j++){
        if (bit & 1 << s[i][j] - 1){
          cnt1++;
        }
      }
      if (cnt1 % 2 == p[i]){
        cnt2++;
      } 
    }
    if (cnt2 == m){
      cnt3++;
    }
  }
  
  
  cout << cnt3 << '\n';
  return 0;
}