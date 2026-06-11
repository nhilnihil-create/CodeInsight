#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n,d,x;
  cin >> n >> d >> x;
  int a[n];
  rep(i,n)cin >> a[i];

  int ans=0;
  d--;
  rep(i,n){
    ans+=d/a[i]+1;
  }
  cout << ans+x << endl;
}
