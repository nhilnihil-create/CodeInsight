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
  ll N;
  cin >> N;
  vector<ll> A(N);
  ll sum = 0;
  ll hu=0;
  ll MIN=INF;
  REP(i, N){
    cin >> A[i];
    if(A[i]<0){
      hu++;
    }
    MIN=min(MIN,abs(A[i]));
    sum+=abs(A[i]);
  }
  
  if(hu%2==0){
    cout << sum << endl;
  }else{
    cout << sum-MIN*2 << endl;
  }
}