#include <bits/stdc++.h>
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP2(i, a, b) for(int i = a;i <= b;i++)
#define REPR(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e18
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
  INT(A);
  INT(B);
  INT(Q);
  VEC(ll,s,A);
  VEC(ll,t,B);
  VEC(ll,x,Q);

  vector<ll> S(A);
  vector<ll> T(B);
  REP(i,A){
    auto itr=upper_bound(ALL(t),s[i]);
    int j=distance(t.begin(),itr);
    if(j==B){
      S[i]=abs(s[i]-t[j-1]);
    }else if(j-1<0){
      S[i]=abs(s[i]-t[j]);
    }else{
      S[i]=min(abs(s[i]-t[j]),abs(s[i]-t[j-1]));
    }
  }
  REP(i,B){
    auto itr=upper_bound(ALL(s),t[i]);
    int j=distance(s.begin(),itr);
    if(j==A){
      T[i]=abs(t[i]-s[j-1]);
    }else if(j-1<0){
      T[i]=abs(t[i]-s[j]);
    }else{
      T[i]=min(abs(t[i]-s[j]),abs(t[i]-s[j-1]));
    }
  }

  REP(i,Q){
    ll MIN = INF;
    auto itr=upper_bound(ALL(s),x[i]);
    int j=distance(s.begin(),itr);
    if(j==A){
      MIN=min(MIN,abs(x[i]-s[j-1])+S[j-1]);
    }else if(j-1<0){
      MIN=min(MIN,abs(x[i]-s[j])+S[j]);
    }else{
      MIN=min(MIN,abs(x[i]-s[j])+S[j]);
      MIN=min(MIN,abs(x[i]-s[j-1])+S[j-1]);
    }
    
    auto itr2=upper_bound(ALL(t),x[i]);
    int k=distance(t.begin(),itr2);
    if(k==B){
      MIN=min(MIN,abs(x[i]-t[k-1])+T[k-1]);
    }else if(k-1<0){
      MIN=min(MIN,abs(x[i]-t[k])+T[k]);
    }else{
      MIN=min(MIN,abs(x[i]-t[k])+T[k]);
      MIN=min(MIN,abs(x[i]-t[k-1])+T[k-1]);
    }
    
    cout << MIN << endl;
  }
}