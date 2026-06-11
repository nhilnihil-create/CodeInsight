#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
  if(b==0) return a;
  if(a%b==0) return b;
  else return gcd(b, a%b);
}
int main(){
  int n, ans=0;
  cin >> n;
  int a[n], l[n+1], r[n+1];
  l[0]=0;
  r[n]=0;
  for(int i=0; i<n; i++)
    cin >> a[i];
  for(int i=0; i<n; i++){
    l[i+1]=gcd(l[i], a[i]);
    r[n-1-i]=gcd(r[n-i], a[n-1-i]);
  }
  for(int i=0; i<n; i++){
    int m=gcd(l[i], r[i+1]);
    if(m>ans) ans = m;
  }
  cout << ans;
  return 0;
}