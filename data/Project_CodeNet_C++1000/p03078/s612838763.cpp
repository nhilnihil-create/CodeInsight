#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long x,y,z,k;cin >>x>>y>>z>>k;
  vector<long long> a(x),b(y),c(z),ab,abc;
  for (int i=0;i<x;i++) cin >> a[i];
  for (int i=0;i<y;i++) cin >> b[i];
  for (int i=0;i<z;i++) cin >> c[i];
  for (int i=0;i<x;i++) {
    for (int j=0;j<y;j++) {
	  ab.push_back(a[i]+b[j]);
	}
  }
  sort(ab.begin(),ab.end());
  reverse(ab.begin(),ab.end());
  for (int i=0;i<min(x*y,k);i++) {
    for (int j=0;j<z;j++) {
	  abc.push_back(ab[i]+c[j]);
	}
  }
  sort(abc.begin(),abc.end());
  reverse(abc.begin(),abc.end());
  for (int i=0;i<k;i++) cout << abc[i] << endl;
}