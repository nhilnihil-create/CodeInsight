#include "bits/stdc++.h"
 
using namespace std;
typedef int64_t ll;
typedef vector<int64_t> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<vd> vvd;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SIZE(a) int((a).size())
const int MAX = 110;
const int MOD = 1000000007;
ll n;vll res(MAX);
void factorize(ll k) {
    for (ll i = 2; i * i <= k; i++) {
        if (k % i != 0) continue;
        while (k % i == 0) {
            k /= i;
            res[i]++;
        } 
    }
    if (k != 1) res[k]++;
    return;
}
int main(){
  cin>>n;
  REP(i,n){
    factorize(i+1);
  }
  vll prime(5);
  REP(i,n+1){
    if(res[i]>=2){prime[0]++;}
    if(res[i]>=4){prime[1]++;}
    if(res[i]>=14){prime[2]++;}
    if(res[i]>=24){prime[3]++;}
    if(res[i]>=74){prime[4]++;}
  }
  ll ans=0;
  if(prime[0]>0){ans+=(prime[0]-1)*prime[3];}
  if(prime[1]>0){ans+=(prime[1]-1)*prime[2];}
  if(prime[0]>0&&prime[1]>1){ans+=(prime[0]-2)*(prime[1]*(prime[1]-1))/2;}
  ans+=prime[4];
  cout<<ans<<endl;
}
