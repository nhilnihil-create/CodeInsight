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
  INT(D);
  INT(G);
  vector<P> A(D);
  REP(i,D) cin >> A[i].first >> A[i].second;

  ll MIN=INF;
  REP(i,1<<D){
    bitset<10> bs(i);
    ll cnt=0;
    ll score=0;
    REP(j,D){
      if(bs[j]==1){
        score+=A[j].second;
        score+=A[j].first*100*(j+1);
        cnt+=A[j].first;
      }
    }

    if(score>G){
      MIN=min(MIN,cnt);
      continue;
    }

    REPR(j,D-1,0){
      if(bs[j]==0){
        ll need=(G-score)/(100*(j+1));
        if((G-score)%(100*(j+1))!=0){
          need++;
        }
        if(need>A[j].first-1){
          score+=(A[j].first-1)*100*(j+1);
          cnt+=A[j].first-1;
        }else{
          cnt+=need;
          score+=need*100*(j+1);
          break;
        }
      }
    }
    if(score<G){
      continue;
    }
    MIN=min(MIN,cnt);
  }
  cout << MIN << endl;
}