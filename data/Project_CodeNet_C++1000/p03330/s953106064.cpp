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
  vector<vector<int>> D(C,vector<int>(C));
  REP(i, C){
    REP(j, C){
      cin >> D.at(i).at(j);
    }
  }
  vector<vector<int>> A(N,vector<int>(N));
  REP(i, N){
    REP(j, N){
      cin >> A.at(i).at(j);
      A.at(i).at(j)--;
    }
  }
  
  vi2 Cost(C,vi(3,0));
  REP(i,C){
    REP(j,N){
      REP(k,N){
        Cost[i][(j+k+2)%3]+=D[A[j][k]][i];
      }
    }
  }

  int MIN = INF;
  REP(i,C){
    REP(j,C){
      REP(k,C){
        if(i!=j&&j!=k&&i!=k){
          MIN=min(MIN,Cost[i][0]+Cost[j][1]+Cost[k][2]);
        }
      }
    }
  }

  cout << MIN << endl;
}