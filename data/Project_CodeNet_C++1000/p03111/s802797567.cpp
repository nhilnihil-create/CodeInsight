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
int N,A,B,C;
int dfs(vector<int> l){
  sort(ALL(l));
  if(l.size()==3){
    return abs(C-l[0])+abs(B-l[1])+abs(A-l[2]);
  }else{
    int MIN = INF;
    REP(i,sz(l)){
      REP(j,sz(l)){
        REP(k,sz(l)){
          if(i!=j&&j!=k&&i!=k){
            MIN=min(MIN,abs(C-l[i])+abs(B-l[j])+abs(A-l[k]));
          }
        }
      }
    }
    REP(i,sz(l)){
      REP(j,i){
        vector<int> x;
        int y = l[i]+l[j];
        REP(k,sz(l)){
          if(k!=i&&k!=j){
            x.push_back(l[k]);
          }
        }
        x.push_back(y);
        MIN=min(MIN,dfs(x)+10);
      }
    }

    return MIN;
  }
}

int main()
{
  cin >> N >> A >> B >> C;
  vector<int> D(N);
  REP(i, N){
    cin >> D[i];
  }
  
  cout << dfs(D) << endl;
}