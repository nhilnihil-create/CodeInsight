#include<bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<int >    vecint;
typedef vector<double >    vecd;
typedef vector<vector<int> >  vec2int;
typedef vector<vector<double> >  vec2d;
typedef vector<ll >     vecll;
typedef vector<string > vecstr;
typedef vector<bool > vecbool;
typedef vector<vector< bool > > vec2bool;
typedef vector<bool > vecbool;
////////////////////////////////////////////////
int main()
{
  int n; cin >> n;
  vecint a(n,0);
  REP(i,n) cin >> a[i];
  int i = 0;
  vecint v;
  REP(i,n){
    int cnt = 1;
    while(i < n - 1&&a[i] == a[i + 1]){
      i ++;
      cnt ++;
    }
    v.push_back(cnt);
  }
  int ans = 0;
  REP(i,v.size()){
    ans += v[i]/2;
  }
  cout << ans << endl;
}