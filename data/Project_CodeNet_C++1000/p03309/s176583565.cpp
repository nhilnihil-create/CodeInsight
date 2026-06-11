#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int a[n];
  rep(i,0,n){
    cin>>a[i];
    a[i]-=i+1;
  }
  sort(a,a+n);
  int mid=a[n/2];
  ll ans=0;
  rep(i,0,n) ans+=abs(a[i]-mid);
  cout<<ans<<endl;
}