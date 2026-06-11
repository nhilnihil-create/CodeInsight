#include <bits/stdc++.h>
using namespace std;

long n,a,b,c,ans=999999999999999,aa,bb,cc;
vector<long> l(8);
vector<long> k(300);
vector<long> x(300,-1);

int main() {
  cin >> n >> a >> b >> c;
  for(long i=0;i<n;i++) cin >> l[i];

  for(long bit=1;bit<(1<<n);bit++) {
    for(long i=0;i<n;i++) {
      if(bit & (1<<i)) {
        k[bit]+=l[i];
        x[bit]++;
      }
    }
  }
  for(long i1=1;i1<(1<<n);i1++) {
    aa=labs(k[i1]-a)+x[i1]*10;
    for(long i2=1;i2<(1<<n);i2++) {
      if((i1&i2)>0) continue;
      bb=labs(k[i2]-b)+x[i2]*10;
      for(long i3=1;i3<(1<<n);i3++) {
        if((i1&i3)>0||(i2&i3)>0) continue;
        cc=labs(k[i3]-c)+x[i3]*10;
        ans=min(ans,aa+bb+cc);
      }
    }
  }
  cout << ans << endl;
}