
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
  int cnt1 = 0,cnt2 = 0;
  string s;
  cin >> s;
  if ((s[2] == '1' || s[2] == '0') && (s[3] >= '0' && s[3] <= '9') && (s[2] != '0' || s[3] != '0')){
    cnt1++;
  }
  if ((s[0] == '0' || s[0] == '2') && (s[1] >= '0' && s[1] <= '9')&& (s[1] != '0' || s[2] != '0')){
    cnt2++;
  }
  if (cnt1 == 1 && cnt2 == 0){
    cout << "YYMM\n";
    return 0;
  }
  if (cnt1 == 0 && cnt2 == 1){
    cout << "MMYY\n";
    return 0;
  }
  if (cnt1 == 0 && cnt2 == 0){
    cout << "NA\n";
    return 0;
  }
  if (cnt1 == 1 && cnt2 == 1){
    cout << "AMBIGUOUS\n";
    return 0;
  }
  return 0;
}