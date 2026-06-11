#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,cx=0,cy=0,hh=0;
  cin >> n;
  vector<long> x(n);
  vector<long> y(n);
  vector<long> h(n);
  for(long i=0;i<n;i++) cin >> x[i] >> y[i] >> h[i];
  for(long i1=0;i1<=100;i1++) {
    for(long i2=0;i2<=100;i2++) {
      long k=100000000000;
      bool ika=true;
      for(long i3=0;i3<n;i3++) {
        if(ika) {
          if(h[i3]==0) {
            k=min(k,labs(i1-x[i3])+labs(i2-y[i3]));
          } else {
            if(k<labs(i1-x[i3])+labs(i2-y[i3])+h[i3]) break;
            k=labs(i1-x[i3])+labs(i2-y[i3])+h[i3];
            ika=false;
          }
        } else {
          if(h[i3]==0) {
            if(k>labs(i1-x[i3])+labs(i2-y[i3])) break;
          } else {
            if(h[i3]!=k-labs(i1-x[i3])-labs(i2-y[i3])) break;
          }
        }
        if(i3+1==n&&k!=0) cx=i1,cy=i2,hh=k;
      }
    }
  }
  cout << cx << " " << cy << " " << hh << endl;
}