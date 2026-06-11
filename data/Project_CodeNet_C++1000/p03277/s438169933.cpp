#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

class BIT{
  static const int MAX_N = 1 << 17;
  int n, bit[MAX_N+1];
public:
  BIT(int n_){
    n = n_;
    for(int i=0; i<n+1; i++) bit[i] = 0;
  }
  //a_1+...+a_iを計算する
  int sum(int i){
    int s = 0;
    while(i>0){
      s+=bit[i];
      i-=i&(-i);
    }
    return s;
  }
  //a_i += xをする(1<=i<=n)
  void add(int i, int x){
    while(i<=n){
      bit[i]+=x;
      i+=i&(-i);
    }
  }
};

ll solve(int X, const vector<ll>& A){
  vector<ll> B;
  rep(i,A.size()){
    if(A[i] >= X) B.push_back(+1);
    else B.push_back(-1);
  }

  vector<ll> sum(B.size()+1);
  sum[0] = 0;
  ll minSum = sum[0];
  rep(i,B.size()){
    sum[i+1] = sum[i] + B[i];
    minSum = min(minSum, sum[i+1]);
  }

  ll maxSum = -10000;
  rep(i,sum.size()){
    sum[i] += -minSum + 1;
    maxSum = max(maxSum, sum[i]);
  }

  BIT bit(maxSum+10);
  ll tmp = 0;
  rep(i,sum.size()){
    tmp += i - bit.sum(sum[i]);
    bit.add(sum[i], 1);
  }

  ll z = A.size();
  ll ret = z * (z+1) / 2 - tmp;
  return ret;
}


int main(){
  int N;
  cin >> N;
  vector<ll> A;
  ll maxA = 0;
  rep(i,N){
    ll a;
    cin >> a;
    A.push_back(a);

    maxA = max(maxA, a);
  }

  ll num = N * (ll)(N+1) / 2;
  num = (num+1) / 2;

  ll lb = 0, ub = maxA+1;
  while(ub-lb>1){
    ll X = (lb+ub)/2;
    ll cnt = solve(X, A);
    //cout << X << " " << cnt << " " << num << endl;
    if(cnt >= num) lb = X;
    else ub = X;
  }

  cout << lb << endl;
  
  return 0;
}
