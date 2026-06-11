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
  y--;
  x--;
  string S,T;
  cin >> S >> T;
  int aokiwinminx=0;
  int aokiwinmaxx=W-1;
  int aokiwinminy=0;
  int aokiwinmaxy=H-1;
  if(S[N-1]=='L') aokiwinminx++;
  if(S[N-1]=='R') aokiwinmaxx--;
  if(S[N-1]=='U') aokiwinminy++;
  if(S[N-1]=='D') aokiwinmaxy--;
  int flag = 0;
  REPR(i,N-2,0){
    if(T[i]=='L'){
      aokiwinmaxx=min(W-1,aokiwinmaxx+1);
    }else if(T[i]=='R'){
      aokiwinminx=max(0,aokiwinminx-1);
    }else if(T[i]=='U'){
      aokiwinmaxy=min(H-1,aokiwinmaxy+1);
    }else if(T[i]=='D'){
      aokiwinminy=max(0,aokiwinminy-1);
    }
    if(aokiwinmaxx<aokiwinminx||aokiwinmaxy<aokiwinminy){
      flag=1;
      break;
    }

    if(S[i]=='L'){
      aokiwinminx++;
    }else if(S[i]=='R'){
      aokiwinmaxx--;
    }else if(S[i]=='U'){
      aokiwinminy++;
    }else if(S[i]=='D'){
      aokiwinmaxy--;
    }    
    if(aokiwinmaxx<aokiwinminx||aokiwinmaxy<aokiwinminy){
      flag=1;
      break;
    }
  }

  if(aokiwinmaxx<x||aokiwinminx>x||aokiwinmaxy<y||aokiwinminy>y){
    flag=1;
  }


  if(flag==1){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
}