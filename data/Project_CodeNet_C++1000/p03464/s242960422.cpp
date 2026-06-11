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
  INT(K);
  vector<ll> A(K);
  REP(i, K) cin >> A[i];
  reverse(ALL(A));
  if(A[0]!=2){
    cout << -1 << endl;
  }else{
    ll MIN=2;
    ll MAX=3;
    int flag = 0;
    FOR(i,1,K){
      if(MIN%A[i]!=0){
        MIN=(MIN/A[i]+1)*A[i];
      }
      MAX=MAX/A[i]*A[i]+A[i]-1;
      if(MAX<MIN){
        flag=1;
        break;
      }
    }

    if(flag==1){
      cout << -1 << endl;
    }else{
      cout << MIN << " " << MAX << endl;
    }
  }
}