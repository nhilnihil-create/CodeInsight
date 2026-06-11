#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  string s; cin >> s;

  int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
  for(int i = 0; i < s.size(); i++){
    if(i % 2){
      if(s[i] == '1') c1++;
      else c2++;
    }
    else{
      if(s[i] == '1') c3++;
      else c4++;
    }
  }
  int ans = min(c1 + c4, c2 + c3);
  cout << ans << endl;
  return 0;
}
