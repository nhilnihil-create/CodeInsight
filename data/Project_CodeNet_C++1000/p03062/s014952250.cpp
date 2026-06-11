#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>> a[i];
  sort(a.begin(),a.end());
  int i=0;
  while(true){
    if(i>n-2) break;
    if(a[i]+a[i+1]<0){a[i]*=-1; a[i+1]*=-1;}
    i+=2;
  }
  ll ans=0;
  rep(i,n) ans+=a[i];
  cout << ans;
}