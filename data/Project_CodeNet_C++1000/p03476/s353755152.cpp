#include <bits/stdc++.h>
#define rep(i,a,n) for (int i =a; (int)i<n; i++) 
using namespace std;

int main() {
  int Q; cin >> Q;
  int l[Q],r[Q]; rep(i,0,Q) cin >> l[i] >> r[i];
  
  bool primeC[100001]; primeC[1] =false; primeC[2] = true;
  int like2017[100001]; like2017[0] = 0; like2017[1] = 0;
  rep(i,2,100001) {
    primeC[i] = true;
    like2017[i] = like2017[i-1];
    if (i >=3) rep(j,2,sqrt(i)+1) if (i % j ==0) primeC[i] = false;
    if (primeC[i] && primeC[(i+1)/2]) like2017[i]++;
  }
  rep(i,0,Q) cout << like2017[r[i]] - like2017[l[i]-1] << endl;
}