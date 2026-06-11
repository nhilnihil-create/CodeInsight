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
  ll K,A,B;
  cin >> K >> A >> B;

  if(A>=B-2){
    cout << K+1 << endl;
  }else{
    if(K<=A){
      cout << K+1 << endl;
    }else if((K-A)%2==1){
      cout << B+(B-A)*(K-A-1)/2 << endl;
    }else if((K-A)%2==0){
      cout << B+(B-A)*(K-A-2)/2+1 << endl;
    }
  }
}