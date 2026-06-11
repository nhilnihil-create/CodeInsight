#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<P>> Graph;

int main(){
 
  ll n;
  cin >> n;
  
  vector <int>x(n),y(n);
  
  REP(i,n) cin >> x[i] >> y[i];
  
  sort(x.begin(),x.end());
  reverse(x.begin(),x.end());
  sort(y.begin(),y.end());
  
  ll ansA = 0,p = 0; int i = 0;
  while(1){
    if(p < x[i]) {
      ansA += x[i]-p;
      p = x[i];
    }
    else break;
    if(p > y[i]) {
      ansA += p-y[i];
      p = y[i];
    }
    else break;
    i++;
  }

  ansA += abs(p);
  
    ll ansB = 0;p = 0;i = 0;
  while(1){

    if(p > y[i]) {
      ansB += p-y[i];
      p = y[i];
    }
    else break;
    if(p < x[i]) {
      ansB += x[i]-p;
      p = x[i];
    }
    else break;
    i++;
  }
  
  ansB += abs(p);
  
  cout << max(ansA,ansB) << endl;
    
  return 0;
}