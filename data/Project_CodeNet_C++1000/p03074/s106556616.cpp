#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

int main(){
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  if(s.size() == 1){
    return cout << 1 << '\n', 0;
  }

  int l = 0, cnt = (s.front() == '0' ? 1 : 0), res = 0;

  for(int r = 1; r < n; ++r){
    // ……10……ごとにcnt++
    if(s[r] == '0' && s[r-1] == '1'){
      ++cnt;
    }
    // cnt>kなら……01……まで左端を動かす
    while(cnt > k){
      ++l;
      if(s[l] == '1' && s[l-1] == '0'){
        --cnt;
      }
    }
    if(cnt <= k){
      if(res < r - l + 1) res = r - l + 1;
    }
  }
  cout << res << '\n';
  return 0;
}