#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
  string s;cin >> s;
  int ans = 0;
  int cnt = 0;
  rep(i,s.size()){
    if(s[i]=='A' || s[i]=='G' || s[i]=='T' || s[i]=='C') {
      cnt++;
      ans = max(ans,cnt);
    }else cnt = 0;
  }
  cout << ans << endl;

  
}