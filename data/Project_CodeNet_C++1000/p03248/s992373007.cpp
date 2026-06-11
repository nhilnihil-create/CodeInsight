#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
#define endl '\n'

using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 1e5 + 5, LG = 19, MOD = 998244353;
const int SQ =320;
const long double EPS = 1e-7;
int n;
string s;
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  cin >> s;
  n = s.size();

  if(s.back()=='1'||s[0]=='0'){
    cout<<-1<<'\n';
    return 0;
  }
  s.pop_back();
  s="#"+s;
  for(int i = 1; i <= n - 1; i++){
    if(s[i]!=s[n-i]){
      cout<<-1<<'\n';
      return 0;
    }
  }

  vector<ii> edges;

  edges.pb({1,2});
  int prv = 2;

  for(int i = 2; i <= n - 1; i++){
    edges.push_back({prv,i+1});
    if(s[i] == '1')prv = i + 1;
  }

  for(auto x:edges)
    cout<<x.F<<' '<<x.S<<'\n';


  return 0;
}
