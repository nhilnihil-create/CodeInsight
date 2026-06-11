#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,m;
  cin>>n>>m;
  int ans=100*(n-m)+1900*m;
  rep(i,0,m){
    ans*=2;
  }
  cout<<ans<<endl;
}