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
  INT(H);
  INT(W);
  INT(N);
  INT(y);
  INT(x);
  string S,T;
  cin >> S >> T;
  map<char,int> mp;
  map<char,int> mp2;
  int flag = 0;
  REP(i,N){
    mp[S[i]]++;
  }
  
  if(x+mp['R']>W){
    int nowx=x;
    REP(i,N){
      if(S[i]=='R'){
        nowx++;
      }
      if(nowx>W){
        flag=1;
      }
      if(T[i]=='L'&&nowx!=1){
        nowx--;
      }

    } 
  }
  if(x-mp['L']<1){
    int nowx=x;
    REP(i,N){
      if(S[i]=='L'){
        nowx--;
      }
      if(nowx<1){
        flag=1;
      }
      if(T[i]=='R'&&nowx!=W){
        nowx++;
      }

    } 
  }
  if(y-mp['U']<1){
    int nowy=y;
    REP(i,N){
      if(S[i]=='U'){
        nowy--;
      }
      if(nowy<1){
        flag=1;
      }
      if(T[i]=='D'&&nowy!=H){
        nowy++;
      }

    } 
  }
  if(y+mp['D']>H){
    int nowy=y;
    REP(i,N){
      if(S[i]=='D'){
        nowy++;
      }
      if(nowy>H){
        flag=1;
      }
      if(T[i]=='U'&&nowy!=1){
        nowy--;
      }

    } 
  }


  if(flag==1){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
}