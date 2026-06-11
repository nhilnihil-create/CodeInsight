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
  map<int,int> a;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
    a[A[i]]++;
  }
  int M;
  cin >> M;
  int flag = 0;
  vector<int> T(M);
  REP(i, M){
    cin >> T[i];
    if(a[T[i]]!=0){
      a[T[i]]--;
    }else if(a[T[i]]==0){
      flag = 1;
    }
  }
  
  if(flag == 1){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
}