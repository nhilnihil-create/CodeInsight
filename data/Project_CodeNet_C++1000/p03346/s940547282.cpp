#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  vector<int> c(n);
  rep(i,n){
    if(a[i]==1){
      c[a[i]-1]=1;
      continue;
    }
    c[a[i]-1]=c[a[i]-2]+1;
  }
  int ans=0;
  rep(i,n) ans=max(ans,c[i]);
  cout<<n-ans<<endl;
}