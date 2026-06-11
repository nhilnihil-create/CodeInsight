#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=100010;
const ll mod=1e9+7;

#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/


int main(){
  int n,k;
  cin >> n >> k;
  vector<ll> a(n,0);
  vector<ll> sum(n+1,0);
  rep(i,n){
    cin >> a[i];
    sum[i+1] = sum[i]+a[i];
  }
  vector<ll> b;
  for(int i=1; i<n+1; i++)for(int j=0; j<i; j++){
    b.emplace_back(sum[i]-sum[j]);
  }
  sort(b.rbegin(),b.rend());
  int m = b.size();
  int keta = 40;
  ll ans = 0;
  vector<int> flag(m+10,1);
  while(keta>=0){
    int cnt = 0;
    rep(i,m){
      if(bit(b[i],keta))if(flag[i]==1){
        cnt++;
        flag[i] = 2;
      }
    }
    if(cnt>=k){
      ans |= (1LL<<keta);
      rep(i,m){
        if(flag[i]==1){ flag[i] = 0; } else if(flag[i]==2){ flag[i] = 1; } 
      }
    } else {
      rep(i,m)if(flag[i]==2){ flag[i] = 1; }
    }
    keta--;
  }
  cout << ans << endl;
  return 0;
}