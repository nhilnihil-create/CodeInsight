#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  
  vector<ll> L(N);
  vector<ll> R(N);
  ll lgcd=A[0];
  ll rgcd=A[N-1];
  L[0]=lgcd;
  R[N-1]=rgcd;
  FOR(i,1,N){
    lgcd=gcd(lgcd,A[i]);
    L[i]=lgcd;
  }
  REPR(i,N-2){
    rgcd=gcd(rgcd,A[i]);
    R[i]=rgcd;
  }
  
  ll MAX = 0;
  REP(i,N){
    if(i!=0&&i!=N-1){
      ll x = gcd(L[i-1],R[i+1]);
      MAX=max(MAX,x);
    }else if(i==0){
      MAX=max(MAX,R[1]);
    }else{
      MAX=max(MAX,L[N-2]);
    }
  }

  cout << MAX << endl;
}