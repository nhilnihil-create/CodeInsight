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
  INT(N);
  INT(C);
  vector<vector<ll>> A(N,vector<ll>(3));
  vector<vector<P>> channel(C,vector<P>());
  REP(i, N){
    REP(j, 3){
      cin >> A.at(i).at(j);
      if(j==0||j==1){
        A[i][j]*=2;
      }
    }
    A[i][2]--;
    channel[A[i][2]].push_back(make_pair(A[i][0],A[i][1]));
  }
  REP(i,C){
    sort(ALL(channel[i]));
  }
  vector<ll> imos(200010,0);

  REP(i,C){
    if(sz(channel[i])!=0){
      ll sta = channel[i][0].first-1;
      ll en = channel[i][0].second;
      FOR(j,1,sz(channel[i])){
        P x=channel[i][j];
        if(en!=x.first){
          imos[sta]++;
          imos[en]--;
          sta=x.first-1;
          en=x.second;
        }else{
          en=x.second;
        }
      }
      imos[sta]++;
      imos[en]--;
    }
  }
  
  ll MAX=0;
  ll sum = 0;
  REP(i,200010){
    sum+=imos[i];
    MAX=max(MAX,sum);
  }
  cout << MAX << endl;
}