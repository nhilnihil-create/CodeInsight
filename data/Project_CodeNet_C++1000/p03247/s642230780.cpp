#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
#define all(x) (x).begin(), (x).end()
const int MOD = 1000000007;
 
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  vector<ll> x(n), y(n);
  ll m ;
  REP(i,n){
      cin >> x[i] >> y[i];
  }
  REP(i,n){
      if(i==0){
          m = (abs(x[i]) + abs(y[i])) %2;
      }else{
          if((abs(x[i]) + abs(y[i])) %2 != m){
              cout << -1 << endl;
              return 0;
              break;
          }
      }
  }
  vector<ll> u(n), v(n);
  int mb=0;
  REP(i,n){
      u[i] = x[i] + y[i];
      v[i] = x[i] - y[i];
      int count=0;
      for(; (abs(u[i])>>count) != 0 || (abs(v[i])>>count) != 0; count++){
      }
      mb = max(mb, count-1);
  }
  vector<ll> arms;
  FORR(i,mb, 0){
      arms.push_back(1LL<<i);
  }
  if(m == 0){
      arms.push_back(1);
  }
  vector<bool> uway[n],vway[n];
  REP(i,n){
      REP(j,arms.size()){
          ll len = arms[j];
          if(u[i]> 0){
              uway[i].push_back(true);
              u[i]-=len;
          }else{
              uway[i].push_back(false);
              u[i]+=len;
          }
          if(v[i]> 0){
              vway[i].push_back(true);
              v[i]-=len;
          }else{
              vway[i].push_back(false);
              v[i]+=len;
          }
      }
  }
  cout << arms.size() << endl;
  REP(i,arms.size()){
      cout << arms[i];
      if(i!=arms.size()-1){
          cout << " ";
      }else{
          cout << endl;
      }
  }
  REP(i,n){
      REP(j,uway[i].size()){
          bool uw, vw;
          uw = uway[i][j];
          vw = vway[i][j];
          if(uw && vw){
              cout << 'R';
          }else if(uw && !vw){
              cout << 'U';
          }else if(!uw && vw){
              cout << 'D';
          }else{
              cout << 'L';
          }
      }
      cout << endl;
  }



}