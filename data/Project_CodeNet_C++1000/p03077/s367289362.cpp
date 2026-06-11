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
  ll N,A,B,C,D,E;
  cin >> N >> A >> B >> C >> D >> E;

  ll x = min(A,min(B,min(C,min(D,E))));

  ll y;
  if(N%x==0){
    y=N/x;
  }else{
    y=N/x+1;
  }

  cout << y-1+5 << endl;
}