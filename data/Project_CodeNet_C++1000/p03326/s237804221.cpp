#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, m, x[1009], y[1009], z[1009],a[1009], mx=0;
  cin >> n >> m;
  for(int i=0;i<n;i++)cin >> x[i] >> y[i] >> z[i];
  for(long long xx: {-1, 1}){
    for(long long yy: {-1, 1}){
      for(long long zz: {-1, 1}){
        for(int i=0;i<n;i++)a[i]=xx*x[i]+yy*y[i]+zz*z[i];
        sort(a, a+n);
        long long sm=0;
        for(int i=0;i<m;i++)sm+=a[n-1-i];
        mx=max(mx, sm);
      }
    }
  }
  cout << mx << endl;
}

