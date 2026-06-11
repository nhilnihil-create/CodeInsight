#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 10;
const int MOD = (int)1e9 + 7;
int cnt[100][100];
int fac[N];
int ff[N];

int powr(int n, int k){
  if(k == 0) return 1;
  int p = powr(n,k/2);
  p = (p * 1ll * p) % MOD;
  if(k % 2 == 1)
    p = (p * 1ll * n) % MOD;
  return p;
}

int ncr(int n, int k){
  int r = fac[n];
  r = (r * 1ll * powr(fac[k],MOD-2))%MOD;
  r = (r * 1ll * powr(fac[n-k],MOD-2))%MOD;
  return r;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  fac[0]=1;
  for(int i = 1; i <= n; i ++ )
    fac[i]=(fac[i-1]*1ll*i)%MOD;
  for(int i = 0 ; i < n; i ++ ){
    ff[i]=ncr(n,i+1);
    ff[i]=(ff[i]*1ll*fac[i])%MOD;
    ff[i]=(ff[i]*1ll*fac[n-i-1])%MOD;
    if(i)
      ff[i]=(ff[i-1]+ff[i])%MOD;
  }
  int h;
  int ans = 0;
  int cur;
  for(int i = 1; i <= n; i ++ ){
    cin >> h;
    cur=ff[n-i];
    cur=(cur+ff[i-1])%MOD;
    cur=(cur-ff[0]+MOD)%MOD;
    ans=(ans+(cur*1ll*h)%MOD)%MOD;
  }
  cout << ans << "\n";
  return 0;
}