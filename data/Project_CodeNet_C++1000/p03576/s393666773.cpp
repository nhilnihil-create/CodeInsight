#include <bits/stdc++.h>
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP2(i, a, b) for(int i = a;i <= b;i++)
#define REPR(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 9223372036854775807
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
  INT(K);
  vector<P> A(N);
  REP(i,N) cin >> A[i].first >> A[i].second;
  
  ll MIN=INF;
  REP(i,N-1){
    REP2(j,i+1,N-1){
      REP(k,N-1){
        REP2(l,k+1,N-1){
          ll R=max(A[j].fi,A[i].fi);
          ll L=min(A[j].fi,A[i].fi);
          ll U=max(A[l].se,A[k].se);
          ll D=min(A[l].se,A[k].se);
          int cnt=0;
          REP(m,N){
            if(A[m].fi>=L&&A[m].fi<=R&&A[m].se<=U&&A[m].se>=D){
              cnt++;
            }
          }
          if(cnt>=K){
            MIN=min(MIN,(R-L)*(U-D));
            // cout << "R" << R << "L" << L << "U" << U << "D" << D << endl;
          }
        }
      }
    }
  }

  cout << MIN << endl;
}
