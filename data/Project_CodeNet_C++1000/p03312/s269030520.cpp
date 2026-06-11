#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
ll MOD = 1000000007;
ll INF = 100000000000000000;
double EPS = 1e-12;
double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

int main(){
  ll N;cin >> N;
  vector<ll> A(N),sum(N+1,0);
  rep(i,N){
    cin >> A[i];
    sum[i+1] = A[i] + sum[i];
  }
  ll ans = INF,mid = 0,left = 0,right = 0;
  ll l = 1,r = N+1;
  while(r-l > 1){
    ll M = (r+l)/2;
    if(sum[M] > sum[N] - sum[M-1]){
      r = M;
    }else{
      l = M;
    }
  }
  mid = l;
  mid = 0;
  FOR(i,1,N){
    ll l = 1,r = mid + i;
    if(r <= 1) continue;
    while(r-l > 1){
      ll M = (r+l)/2;
      if(sum[M] > sum[mid+i] - sum[M-1]){
        r = M;
      }else{
        l = M;
      }
    }
    left = l;
    l = mid + i;r = N+1;
    if(l >= N) continue;
    while(r-l > 1){
      ll M = (r+l)/2;
       if(sum[M] - sum[mid+i] > sum[N] - sum[M-1]){
        r = M;
      }else{
        l = M;
      }
    }
    right = l;
    //cout << left << ' ' << mid + i << ' ' << right << endl;
    FOR(j,-2,3){
      FOR(k,-2,3){
        ll L = left+j;
        ll RI = right + k;
        ll MID = mid+i;
        if(1 <= L && L < MID && MID < RI && RI <= N){
          ll P,Q,R,S;
          //cout << L << ' ' << MID << ' ' << RI << endl;
          P = sum[L];Q = sum[MID] - sum[L];R = sum[RI] - sum[MID];S = sum[N] - sum[RI];
          //cout << P+Q+R+S << endl;
          ans = min(ans,max({P,Q,R,S})-min({P,Q,R,S}));
        }else{
          continue;
        }
      }
    }
  }
  cout << ans << endl;
}