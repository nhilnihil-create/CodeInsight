#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;
int main() {
  int a,b,x;
  cin>>a>>b>>x;
  if(a<=x&&x<=a+b) cout<<"YES";
  else cout<<"NO";
  return 0;
}