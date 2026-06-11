#include<bits/stdc++.h>
using namespace std;
#define rall(v) v.rbegin(),v.rend()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  int ans=0;
  rep(i,n) {
    cin>>a[i];
    ans+=a[i];
  }
  sort(rall(a));
  ans-=a[0]/2;
  cout<<ans<<endl;
}