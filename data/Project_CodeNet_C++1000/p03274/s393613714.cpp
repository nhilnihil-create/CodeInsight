#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

int main(){
  int n,k;
  cin >> n >> k;
  vi a(n);
  rep(i,n) cin >> a[i];
  int ans=300000005;
  rep(i,n-k+1){
    if(a[i]<0){
      if(a[i+k-1]<0){
        ans=min(ans,-1*a[i]);
      }
      else{
        int m=min(-1*a[i],a[i+k-1]),M=max(-1*a[i],a[i+k-1]);
        ans=min(ans,2*m+M);
      }
    }else{
      ans=min(ans,a[i+k-1]);
    }
  }
  cout << ans;
  return 0;
}