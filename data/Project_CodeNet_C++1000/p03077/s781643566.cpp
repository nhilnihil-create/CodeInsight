#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
#define all(v) v.begin(), v.end()

int main(){
  ll N,A,B,C,D,E,x;
  cin >> N >> A >> B >> C >> D >> E;
  x=min(A,min(B,min(C,min(D,E))));
  x=(N-1)/x+1;
  cout << x+4 << endl;
}