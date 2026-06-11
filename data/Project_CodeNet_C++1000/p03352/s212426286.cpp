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
  int X;
  cin >> X;

  if(X == 1){
    cout << 1 << endl;
  }else{
    int MAX = 0;
    FOR(i,2,32){
      int a = i;
      FOR(j,2,11){
        a*=i;
        if(a <= X){
          MAX = max(MAX,a);
        }else{
          break;
        }
      }
    }
    cout << MAX << endl;
  }
}