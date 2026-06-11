#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  int n;
  string s;
  cin >> n >> s;
  int mxcnt = 0;
  REP2(k,1,n-1){
    map<char, bool> mp;
    int cnt = 0;
    REP2(i,0,k){
      mp[s[i]] = true;
    }
    REP2(i,k,n){
      if(mp[s[i]] == true){
        cnt++;
        mp[s[i]] = false;
      }
    }
    mxcnt = max(mxcnt, cnt);
  }

  cout << mxcnt << endl;
  
  return 0;
}
