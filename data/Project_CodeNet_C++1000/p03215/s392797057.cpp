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

int main()
{
  ll N,K;
  cin >> N >> K;
  VEC(ll,A,N);
  ll sum = 0;
  vector<ll> imos(1,0);
  REP(i,N){
    sum+=A[i];
    imos.push_back(sum);
  }
  vector<ll> bf;
  REP(i,N){
    REP(j,i){
      bf.push_back(imos[i+1]-imos[j]);
    }
  }
  sort(ALL(bf));
  reverse(ALL(bf));
  // REP(i,sz(bf)){
  //   cout << bf[i] << endl;
  // }
  ll ans=0;
  REPR(i,99,0){
    int cnt = 0;
    vector<ll> newbf;
    REP(j,sz(bf)){
      bitset<100> bs(bf[j]);
      if(bs[i]==1){
        cnt++;
        newbf.push_back(bf[j]);
      }
    }
    if(cnt>=K){
      bf=newbf;
      ans+=pow(2,i);
      // cout << i << endl;
    }
  }

  cout << ans << endl;
}