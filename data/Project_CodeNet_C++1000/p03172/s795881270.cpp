#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
      d[i]%=MOD;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
};

#define MAXN 100
#define MAXK 100000

int dp[MAXN+1][MAXK+1];

int main(){
  int n,K;cin>>n>>K;
  vector<int>a(n);
  rep(i, n)cin>>a[i];

  BIT<ll> bit(K+1);
  bit.add(0, 1);

  dp[0][0]=1;

  rep(i, n){
    BIT<ll> tbit(K+1);
    rep(j, K+1){
      int l = max(0, j-a[i]);
      int r = j;

      // BITで累積和を求める
      ll sum = bit.sum(r);
      if(l>=1)sum-=bit.sum(l-1);
      sum %= MOD;

      tbit.add(j, sum);
//      cout<<sum<<' ';
    }
//    cout<<endl;
    swap(bit, tbit);
  }
  ll result = bit.sum(K);
  if(K){
    result = (result - bit.sum(K-1)+2*MOD)%MOD;
  }
  cout<<(result+MOD)%MOD<<endl;

  return 0;
}

