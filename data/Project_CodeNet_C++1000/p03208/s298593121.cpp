#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
  ll h[100010];
  ll min=2000000000;
  rep(i,n)cin>>h[i];
  sort(h,h+n,greater<int>());
  // rep(i,n)cout<<h[i]<<endl;
  rep(i,n-k+1){
    ll tmp=h[i]-h[i+k-1];
    if(tmp<min){
      min=tmp;
    }
  }
  cout<<min<<endl;
  return 0;
}
