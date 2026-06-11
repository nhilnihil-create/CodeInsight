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
  ll a, b, c, k; cin >> a >>b >> c>> k;
  // a_{n + 1}  - b_{n + 1} = b_n + c_n - (c_n + a_n) = (b_n - a_n)
  if(k % 2 == 0){
    cout << a - b << endl;
  }else{
    cout << b - a << endl;
  }
} 