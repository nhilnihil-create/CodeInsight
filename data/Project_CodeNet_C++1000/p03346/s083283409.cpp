#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
    A[i]--;
  }

  vector<int> B(N);
  REP(i,N){
    B[A[i]]=i;
  }

  int cnt = 0;
  int MAX = 0;
  B.push_back(-1);
  REP(i,N){
    if(B[i]<B[i+1]){
      cnt++;
    }else{
      cnt++;
      MAX=max(MAX,cnt);
      cnt=0;
    }
  }

  cout << N-MAX << endl;
}