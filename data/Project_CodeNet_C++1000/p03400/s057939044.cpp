#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,d,x;
  cin>>n>>d>>x;
  int ans=0;
  rep(i,0,n){
    int a;
    cin>>a;
    ans+=(d-1)/a+1;
  }
  cout<<ans+x<<endl;
}