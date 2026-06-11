#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
const ll inf = 1e16;
const ll md = 1000000007;

int main() {
  int n,q,k;
  string s;
  cin>>n>>s>>q;
  rep(_,q){
    cin>>k;
    ll ans=0LL;
    ll d=0,m=0,dm=0;
    rep(i,n){
      if (i-k>=0){
        if (s[i-k]=='D') {--d;dm-=m;}
        if (s[i-k]=='M') --m;
      }
      if (s[i]=='D') ++d;
      if (s[i]=='M') {++m;dm+=d;}
      if (s[i]=='C') ans+=dm;
    }
    cout<<ans<<endl;
  }
  return 0;
}