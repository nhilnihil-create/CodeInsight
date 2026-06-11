#include<bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long unsigned int ll;
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
  int n, a, b; cin >> n >> a >> b;
  if((b - a)%2 == 0){
    cout << "Alice" << endl;
  }else{
    cout << "Borys" << endl;
  }
} 