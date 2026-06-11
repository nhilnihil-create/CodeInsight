#include <bits/stdc++.h>
#include <queue>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  int ans=0;
  rep(i,n){
    ans=ans+a[i]-1;
  }
  cout<<ans<<endl;
  

  return 0;
}
