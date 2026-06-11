#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  string s;
  cin >> s;
  int l = s.size();
  vector<int> v(10,0);
  int cnt1 = 0;
  int cnt2 = 0;
  rep(i,l){
    if(s.at(i) == 'A' || s.at(i) == 'T' || s.at(i) == 'G' || s.at(i) == 'C'){
      cnt1++;
    	if(i == l-1){
        v[cnt2] = cnt1;
        }
    }
    else{
      v[cnt2] = cnt1;
      cnt1 = 0;
      cnt2++;
    }
  }
  int ans = 0;
  rep(i,10){
    ans = max(v[i],ans);
  }
  cout << ans << endl;
}
  