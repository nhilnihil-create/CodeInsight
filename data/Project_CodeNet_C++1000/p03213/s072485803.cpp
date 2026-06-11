#include <bits/stdc++.h>
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP2(i, a, b) for(int i = a;i <= b;i++)
#define REPR(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define PI 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define vi2 vector<vector<int>>
#define eb emplace_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
using P = pair<ll,ll>;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};
#define INT(name) int name;cin >> name;
#define VEC(type,name,n) vector<type> name(n);REP(i,n) cin >> name[i];

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

map<ll, int> prime_factor(ll n) {
  map<ll, int> ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main()
{
  INT(N);
  map<ll,int> mp;
  FOR(i,1,N+1){
    map<ll,int> mp1=prime_factor(i);
    for(auto p:mp1){
      mp[p.fi]+=p.se;
    }
  }
  ll cnt2=0;
  ll cnt4=0;
  ll cnt14=0;
  ll cnt24=0;
  ll cnt74=0;
  for(auto x:mp){
    if(x.se>=2){
      cnt2++;
    }
    if(x.se>=4){
      cnt4++;
    }
    if(x.se>=14){
      cnt14++;
    }
    if(x.se>=24){
      cnt24++;
    }
    if(x.se>=74){
      cnt74++;
    }
  }
  cout << (cnt2-2)*(cnt4*(cnt4-1)/2)+(cnt2-1)*cnt24+(cnt4-1)*cnt14+cnt74 << endl;
}