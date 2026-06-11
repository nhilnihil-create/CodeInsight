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
typedef pair<str,str> p;

int main(){
  ll n;
  cin >> n;
  str s;
  cin >> s;
  map<p,ll> mp;
  str s_first = s.substr(0,n);
  str s_second = s.substr(n,n);
  reverse(s_second.begin(),s_second.end());
  REP(i,1<<n){
    str temp, temp2;
    REP(j,n){
      if(i>>j&1) temp += s_second[j];
      else temp2 += s_second[j];
    }
    mp[p(temp,temp2)]++;
  }
  ll ans = 0;
  REP(i,1<<n){
    str temp, temp2;
    REP(j,n){
      if(i>>j&1) temp += s_first[j];
      else temp2 += s_first[j];
    }
    ans += mp[p(temp,temp2)];
  }
  cout << ans << endl;
  return 0;
}
