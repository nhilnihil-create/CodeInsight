#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  rep(i,n)cin >> a[i];

  long long ans=0;
  rep(i,n)ans+=a[i];
  cout << ans-n << endl;
}