#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;

int main() {
  int MAX=pow(10,5)+1;
  vi is_prime(MAX,1);
  is_prime[0]=0,is_prime[1]=0;
  rep(i,2,sqrt(MAX)) {
    if (is_prime[i]==0) {
      continue;
    }
    for (int j=i*2;j<MAX;j+=i) {
      is_prime[j]=0;
    }
  }
  vi a(MAX,0);
  rep(i,0,MAX) {
    if (i%2==0) {
      continue;
    } else if (is_prime[i] && is_prime[(i+1)/2]) {
      a[i]=1;
    }
  }
  vi s(MAX+1,0);
  rep(i,0,MAX) {
    s[i+1]=s[i]+a[i];
  }
  int Q; cin >>Q;
  rep(q,0,Q) {
    int l,r; cin >>l >>r;
    r++;
    cout <<s[r]-s[l] <<endl;
  }
  return 0;
}
