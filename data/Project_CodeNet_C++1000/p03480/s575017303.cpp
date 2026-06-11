#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <map>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

int main(){
  str s;
  cin >> s;
  ll n = s.length();
  ll ans = INF;
  ll changed = false;
  REP(i,n-1){
    if(s[i]!=s[i+1]){
      ans = min(ans,max(i+1,n-i-1));
      changed = true;
    }
  }
  if(!changed){
    cout << n << endl;
  }else{
    cout << ans << endl;
  }
  return 0;
}
