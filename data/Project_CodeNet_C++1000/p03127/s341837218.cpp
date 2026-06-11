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
    int N; cin >> N;
    vi a(N);rep(i,N) cin>>a[i];
    int ans=a[0];
    rep(i,N-1) ans=gcd(ans,a[i+1]);
  
    cout << ans << endl;
    return 0;
}
