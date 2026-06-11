#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long int ll;
typedef vector<int >    vecint;
typedef vector<ll >      vecll;
typedef vector<double >   vecd;
typedef vector<string > vecstr;
typedef vector<char >  vecchar;
typedef vector<bool >  vecbool;
typedef vector<vector<bool> >  vec2bool;
typedef vector<vector<int> >    vec2int;
typedef vector<vector<double> >   vec2d;
////////////////////////////////////////////////
int main()
{
  int n; cin >> n;
  vecint b(n,0); REP(i,n)cin >> b[i];
  vecint ans(n,0);
  bool ok = false;
  REP(i,n){
    // REP(i,b.size() - 1)cout << b[i] << " ";
    // cout << endl;
    int ind = 0;
    ok = false;
    for(int j = b.size() - 1; j >= 0; j --){
      if(b[j] == j + 1){
	ind = j;
	ok = true;
	break;
      }
    }
    if(ok){
      ans[n - i - 1] = b[ind];
      b.erase(b.begin() + ind);
    }else{
      break;
    }
  }
  // cout << "finish" << endl;
  if(!ok){cout << -1 << endl;return 0;}
  REP(i,n){
    cout << ans[i] << endl;
  }
}