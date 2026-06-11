#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// 文字列の最初の位置、最後の位置(0-index)の部分文字列が回文となっているか判定
bool kaibunCheck(string s, int l, int r){
  if(s.size() == 0) return true;
  int n = s.size();
  if(l < 0 || l > n-1 || l > r || r < 0 || r > n-1) return false;
  bool flag = true;
  for(int i = l; i <= r; i++){
    if(s[i] != s[r-i]) flag = false;
  }
  return flag;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S; cin >> S;
  string SS;
  int N = S.size();
  REP(i, N){
    if(S[i] != 'x') SS += S[i]; 
  }
  if(kaibunCheck(SS, 0, SS.size()-1)){
    int left = 0, right = N-1, ans = 0;
    while(left <= right){
      if(S[left] == 'x' && S[right] != 'x'){
        left++; ans++;
      }
      if(S[right] == 'x' && S[left] != 'x'){
        right--; ans++;
      }
      if(S[left] == S[right]){
        left++; right--;
      } 
    }
    cout << ans << endl;
  }else{
    cout << -1 << endl;
  }
}