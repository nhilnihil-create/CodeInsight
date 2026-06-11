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
  ll R, G, B, N;
  cin >> R >> G >> B >> N;

  if(R==1&&G==1&&B==1){
    cout << (N+2)*(N+1)/2 << endl;
  }else{ 
    ll cnt = 0;
    REP(i,N/R+2){
      REP(j,(N-i*R)/G+2){
        REP(k,(N-i*R-j*G)/B+2){
          if(i*R+j*G+k*B==N){
            cnt++;
          }
        }
      }
    }
    cout << cnt << endl;
  }
}