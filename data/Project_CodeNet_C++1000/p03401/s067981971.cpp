#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF=1001001;
int main(){
  int n;
  cin>>n;
  vector <int>a(n+2);
  a[0]=0;a[n]=0;
  rep(i,n)cin>>a[i+1];

  vector<int>l1(n+1,0);
  vector<int>l2(n,0);
  int tot=0;

  rep(i,n+1){
    l1[i]=abs(a[i+1]-a[i]);
    tot+=l1[i];
  }
  rep(i,n){
  l2[i]=abs(a[i+2]-a[i]);
}
rep(i,n){
  int ans=tot-l1[i]-l1[i+1];
  ans+=l2[i];
  cout<<ans<<endl;
}








}
