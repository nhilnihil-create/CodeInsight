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
  int n,m; cin >>n >>m;  
  vector<int>s[m]; int p[m],sum=0;
  for(int i=0; i<m; i++){
    int k; cin >>k;
    for(int j=0; j<k; j++){
      int x; cin >>x;
      s[i].push_back(x);
    }
  }
  for(auto &i:p) cin >>i;
  for(int i=0; i<1<<n; i++){
    int x=i;
    bool b[n],bb=1; memset(b,0,sizeof(b));
    for(int j=0; j<n; j++){
      b[j]=x%2; x/=2;
    }
    for(int j=0; j<m; j++){
      int cnt=0;
      for(auto z:s[j]) if(b[z-1]) cnt++;
      if(cnt%2!=p[j]){bb=0; break;}
    }
    if(bb) sum++;
  }
  cout <<sum;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  solve();
return 0;}