#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD=1e9+7;
const int INF32=1<<30;
const ll INF64=1LL<<60;

void solve(){
  int n; cin >>n;
  vector<tuple<string,int,int>>v;
  for(int i=0; i<n; i++){
  string s; int p; cin >>s >>p; p*=-1;
  v.push_back(make_tuple(s,p,i+1));
  }
  sort(v.begin(),v.end());
  for(auto x:v) cout <<get<2>(x)<<'\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  solve();
return 0;}