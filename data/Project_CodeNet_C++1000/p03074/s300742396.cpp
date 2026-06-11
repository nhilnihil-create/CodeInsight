#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> memo(100005, 0);
  int l=0, r=0, ans = 0, nans = 0;
  bool frag1 = false;
  for(int i=0; i<n; ++i){
    if(s[i] == '0'){
      if(frag1){
        ++memo[r];
        ++nans;
      }else{
        frag1 = true;
        if(k>0) --k;
        else{ nans -= memo[l]; ++l;}
        ++memo[r];
        ++nans;
      }
    }
    else{ //s[i] == "1"
      if(frag1){
        frag1 = false;
        ++r;
      }
      ++memo[r];
      ++nans;
    }
    ans = max(nans, ans);
    //cout << "i:" << i << " nans:" << nans << " ans:" << ans << endl;
  }
  ans = max(memo[r]-memo[l], ans);
  cout << ans << endl;
}