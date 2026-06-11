#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int n;
  cin>>n;
  int a[200005];
  rep(i,n) cin>>a[i];
  int x=0;
  ll ans=0;
  for(int l=0,r=0;l<n;l++){
    while(r<=n){
      if(r==n||(x^a[r])!=x+a[r]) break;
      x^=a[r];
      r++;
    }
    ans+=r-l;
    x^=a[l];
  }
  cout<<ans<<endl;
  return 0;
}