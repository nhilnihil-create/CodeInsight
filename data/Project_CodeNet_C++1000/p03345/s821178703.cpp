#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
 
int main()
{
  ll A, B, C, K;
  cin >> A >> B >> C >> K;

  if(A-B > 1000000000000000000 || B-A > 1000000000000000000){
    cout << "Unfair" << endl;
  }else{
    if(K%2 == 0){
      cout << A-B << endl;
    }else{
      cout << B-A << endl;
    }
  }
}