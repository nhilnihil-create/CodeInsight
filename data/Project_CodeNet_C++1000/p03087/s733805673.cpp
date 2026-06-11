#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
  long N,Q;
  cin>>N>>Q;
  string s;
  cin>>s;
  long l[Q],r[Q];
  rep(i, Q){
    cin>>l[i]>>r[i];
  }

  vector<long> sum(N, 0);
  FOR(i, 1, N){
    if(s[i-1] == 'A' && s[i] == 'C'){
      sum[i-1] = 1;
    }
  }

  long a[N+1];
  a[0] = 0;
  FOR(i, 1, N){
    a[i] = a[i-1] + sum[i-1];
  }

  rep(i, Q){
    cout << a[r[i]-1]-a[l[i]-1]<<endl;
  }
}
