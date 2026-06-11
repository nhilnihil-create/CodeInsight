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
int sumdig(string a)
{
  int res = 0;
  REP(i,a.size()){
    res += a[i] - '0';
  }
  return res;
}
int main()
{
  int n; cin >> n;
  int ans = 1e9;
  for(int i = 1; i <= n - 1; i++){
    string s = to_string(i);
    string t = to_string(n - i);
    int tmp = sumdig(s) + sumdig(t);
    ans = min(tmp, ans);
  }
  cout << ans << endl;
}
