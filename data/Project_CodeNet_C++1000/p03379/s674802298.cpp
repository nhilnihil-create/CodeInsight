#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;
using vs=vector<string>;

int main() {
  int N; cin >>N;
  vll X(N);
  rep(i,0,N) {cin >>X[i];}
  vll Y(N);
  Y=X;
  sort(all(Y));
  int m=N/2;
  int mida=Y[m-1];
  int midb=Y[m];
  rep(i,0,N) {
    if (X[i]<=mida) {
      cout <<midb <<endl;
    } else {
      cout <<mida <<endl;
    }
  }
  return 0;
}
