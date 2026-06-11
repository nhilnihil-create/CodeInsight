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
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  
  int MIN = INF;
  REP(i,N-K+1){
    if(A[i]<0&&A[i+K-1]<=0){
      MIN=min(MIN,-A[i]);
    }else if(A[i]<0&&A[i+K-1]>0&&A[i+K-1]<=-A[i]){
      MIN=min(MIN,A[i+K-1]*2-A[i]);
    }else if(A[i]<0&&A[i+K-1]>0&&A[i+K-1]>A[i]){
      MIN=min(MIN,-A[i]*2+A[i+K-1]);
    }else if(A[i]>=0&&A[i+K-1]>=0){
      MIN=min(MIN,A[i+K-1]);
    }
  }

  cout << MIN << endl;
}