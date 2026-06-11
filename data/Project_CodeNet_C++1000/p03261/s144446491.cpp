
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
  int n,m,cnt2 = 0;
  cin >> n;
  vector<string> w(n);
  map<string,int> cnt;
  for (int i = 0; i < n; i++){
    cin >> w[i];
    if (i != 0 && cnt2 == 0 && (w[i-1][m-1] != w[i][0] || cnt[w[i]] != 0)){
      cout << "No\n";
      cnt2++;
    }
    m = w[i].size();
    cnt[w[i]]++;
  }
  if (cnt2 == 0){
    cout << "Yes\n";
  } 
  return 0;
}