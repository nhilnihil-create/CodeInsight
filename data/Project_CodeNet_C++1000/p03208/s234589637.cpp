#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  int h[n];
  rep(i,n)cin >> h[i];

  sort(h,h+n);
  int ans=1000000000;
  rep(i,n-k+1){
    int tmp=h[k-1+i]-h[i];
    if(ans>tmp)ans=tmp;
  }
  cout << ans << endl;;
}
