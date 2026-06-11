#include <bits/stdc++.h>
using namespace std;

int main() {
  long x,y,z,k;
  cin >> x >> y >> z >> k;
  vector<long> a(x);
  vector<long> b(y);
  vector<long> c(z);
  vector<long> ans;
  for(long i=0;i<x;i++) cin >> a[i];
  for(long i=0;i<y;i++) cin >> b[i];
  for(long i=0;i<z;i++) cin >> c[i];

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  for(long d=x-1;d>=0&&x-d-1<k;d--) {
    for(long e=y-1;e>=0&&(x-d)*(y-e)-1<k;e--) {
      for(long f=z-1;f>=0&&(x-d)*(y-e)*(z-f)-1<k;f--) {
        ans.push_back(0-a[d]-b[e]-c[f]);
      }
    }
  }
  sort(ans.begin(),ans.end());
  for(long i=0;i<k;i++) cout << 0-ans[i] << endl;
}