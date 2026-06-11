#include <bits/stdc++.h>
using namespace std;

int main() {
  long h,w,d,q;
  cin >> h >> w >> d;
  vector<long> x(h*w);
  vector<long> y(h*w);
  vector<long> aaa(h*w);
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      long num;
      cin >> num;
      x[num-1]=j;
      y[num-1]=i;
    }
  }
  for(int i=d;i<h*w;i++) {
    aaa[i]=aaa[i-d];
    aaa[i]+=max(x[i]-x[i-d],x[i-d]-x[i]);
    aaa[i]+=max(y[i]-y[i-d],y[i-d]-y[i]);
  }
  cin >> q;
  vector<long> ans(q);
  for(int i=0;i<q;i++) {
    long l,r;
    cin >> l >> r;
    ans[i]=aaa[r-1]-aaa[l-1];
  }
  for(int i=0;i<q;i++) cout << ans[i] << endl;
}