#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N;
  cin >> N;
  map<char, ll> cnt;
  string S;
  rep(i, N){
    cin >> S;

    cnt[S[0]]++;
  }

  ll ans = 0;
  ans += cnt['M']*cnt['A']*cnt['R'];
  ans+= cnt['M']*cnt['A']*cnt['C'];
  ans+= cnt['M']*cnt['A']*cnt['H'];
  ans += cnt['M']*cnt['R']*cnt['C'];
  ans += cnt['M']*cnt['R']*cnt['H'];
  ans += cnt['M']*cnt['C']*cnt['H'];
  ans += cnt['A']*cnt['R']*cnt['C'];
  ans += cnt['A']*cnt['R']*cnt['H'];
  ans += cnt['A']*cnt['C']*cnt['H'];
  ans += cnt['R']*cnt['C']*cnt['H'];

  cout << ans << endl;
  
  return 0;
}
