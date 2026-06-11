#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb(x) push_back(x)

typedef long long ll;
typedef pair<int, int> point;

const int baza = 1307, mod = 1e9 + 7, MAX = (1 << 18);

inline int add(int x, int y){
  x += y;
  if(x >= mod) return x - mod;
  return x;
}

inline int mul(ll x, ll y){
  return x * y % mod;
}

int n, mid;
string s;
point hesh[MAX][2];

int heshaj(int mask, int extra){
  int ret = 0;
  REP(i, mid){
    if( (mask & (1 << i)) == 0) continue;
    ret = add(mul(ret, baza), s[i + extra]);
  }
  return ret;
}

map<point, int> M[2];

int revHashaj(int mask, int extra){
  int ret = 0;
  for(int i = mid - 1; i >= 0; --i){
    if( (mask & (1 << i)) == 0) continue;
    ret = add(mul(ret, baza), s[i + extra]);
  }
  return ret;
}

void brut(int extra){
  REP(mask, (1 << mid)){
    if(!extra) hesh[mask][0].first = heshaj(mask, extra);
    else hesh[mask][1].first = revHashaj(mask, extra);
    int newMask = (1 << mid) - 1;
    newMask ^= mask;
    if(!extra) hesh[mask][0].second = revHashaj(newMask, extra);
    else hesh[mask][1].second = heshaj(newMask, extra);
    M[extra != 0][hesh[mask][extra != 0]] ++;
  }
}

int main(){
  cin >> n >> s;
  mid = n;
  brut(0); brut(mid);
  ll sol = 0;

  for(auto it : M[0]){
    sol += (ll)it.second * M[1][it.first];
  }
  cout << sol;
}
