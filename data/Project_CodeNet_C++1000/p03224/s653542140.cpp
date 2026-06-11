#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(obj) (obj).begin(), (obj).end()
#define pb push_back
const double pi = acos(-1);
const double EPS = 1e-10;

vi solve(int i,int j,vii ans){
  vi res(i);
  if (j == 0) {
    REP(k,i) res[k] = k+1;
    return res;
  } else {
    for (int k = 0; k < i; k++) {
      if(k < j){
        res[k] = ans[k][j-1];
      }else if(k == j){
        res[k] = ans[j-1].back() + 1;
      }else{
        res[k] = res[k-1] + 1;
      }
    }
    return res;
  }
}

int main(){
  int n;
  cin >> n;
  bool flag = false;
  int i = 1;
  for (; i*(i+1)/2 <= n; i++) {
    if (i*(i+1)/2 == n) {
      flag =true;
      break;
    }
  }
  if (flag) {
    cout << "Yes" << endl;
    cout << i+1 << endl;
    vii ans;
    REP(j,i+1){
      cout << i;
      ans.pb(solve(i,j,ans));
      REP(k,i){
        cout << " " << ans[j][k];
      }
      cout << endl;
    }
  } else {
    cout << "No" << endl;
  }
}