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

  ll sum = 0;
  ll B[100010]={0};
  vector<ll> A(N);
  REP(i, N){
    cin >> A[i];
    if(A[i]>N){
      sum++;
      continue;
    }else{
      B[A.at(i)-1]++;
    }
  }
  REP(i,N){
    if(B[i]<i+1){
      sum+=B[i];
    }else{
      sum+=B[i]-i-1;
    }
  }
  cout << sum << endl;
}