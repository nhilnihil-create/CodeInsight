#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;
using vs=vector<string>;

int main() {
  ll N; cin >>N;
  ll cnt=1;
  ll ans=0;
  bool flag=true;
  while (N>=10) {
    if (N%10!=9) {
      flag=false;
    }
    N/=10;
    cnt++;
  }
  if (flag) {
    ans=N+9*(cnt-1);
  } else {
    ans=N+9*(cnt-1)-1;
  }
  cout <<ans <<endl;
  return 0;
}
