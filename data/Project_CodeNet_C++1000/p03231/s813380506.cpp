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

int gcd(int a, int b){
  if (a%b == 0){
    return(b);
  }else{
    return(gcd(b, a%b));
  }
}
int lcm(int a, int b){
  return a * b / gcd(a, b);
}

int main()
{
  ll N,M;
  cin >> N >> M;
  string S,T;
  cin >> S >> T;

  ll GCD = gcd(N,M);

  int flag = 0;
  REP(i,GCD){
    if(S.at(i*N/GCD)!=T.at(i*M/GCD)){
      flag = 1;
    }
  }

  if(flag ==1){
    cout << -1 << endl;
  }else{
    cout << M*N/GCD << endl;
  }
}