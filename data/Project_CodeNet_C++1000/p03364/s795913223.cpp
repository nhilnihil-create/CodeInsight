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
  vector<string> A(N);
  REP(i, N) cin >> A[i];
  REP(i,N){
    A[i]=A[i]+A[i];
  }
  REP(i,N){
    A.push_back(A[i]);
  }

  ll cnt = 0;
  REP(i,N){
    int y = 0;
    int x = i;
    int flag= 0;
    REP(j,N){
      REP(k,N){
        int ny = y+j;
        int nx = x+k;
        if(A[ny][nx]!=A[nx-x][ny+x]){
          flag = 1;
        }
      }
    }
    if(flag==0){
      cnt+=N-i;
    }
  }

  FOR(i,1,N){
    int y = i;
    int x = 0;
    int flag= 0;
    REP(j,N){
      REP(k,N){
        int ny = y+j;
        int nx = x+k;
        if(A[ny][nx]!=A[nx+y][ny-y]){
          flag = 1;
        }
      }
    }
    if(flag==0){
      cnt+=N-i;
    }
  }

  cout << cnt << endl;
}