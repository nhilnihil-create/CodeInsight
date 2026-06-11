#include <bits/stdc++.h>

using namespace std;
const long long MAX=1e15;

int main(){
  long long k, a[100009];
  cin >> k;
  for(int i=0;i<k;i++)cin >> a[i];
  long long l=2, r=2;
  for(int i=k-1;i>=0;i--){
    long long x=((l-1)/a[i]+1)*a[i];
    long long y=r/a[i]*a[i];
    if(y<x){
      cout << -1 << endl;
      return 0;
    }
    l=x;
    r=y+a[i]-1;
  }
  cout << l << ' ' << r << endl;
}

