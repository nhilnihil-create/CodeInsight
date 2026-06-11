#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

int main(){
  int n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll ans=1e15;
  rep(i,n-k+1){
    if(a[i+k-1]<0){ans=min(-1*a[i],ans);continue;}
    if(a[i]>0){ans=min(a[i+k-1],ans);continue;}
    ans=min(2*min(-1*a[i],a[i+k-1])+max(-1*a[i],a[i+k-1]),ans);
  }
  cout << ans;
  return 0;
}