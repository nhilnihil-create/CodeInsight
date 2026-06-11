//
#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);

int gcd(int a,int b){
  if(a<b) swap(a,b);
  while(a%b){
    int r = a%b;
    a=b;
    b=r;
  }
 return b;
}

int main() {
    int N,M; cin >> N>>M;
    vi a(M);rep(i,M) cin>>a[i];
    sort(a.begin(),a.end());
    vi d(M-1);rep(i,M-1) d[i]=a[i+1]-a[i];
    sort(d.begin(),d.end());
  
    ll ans=0;
    rep(i,M-N) ans+=d[i];
  
    cout << ans << endl;
    return 0;
}
