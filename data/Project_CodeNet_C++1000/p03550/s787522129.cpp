#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
signed main(){
  int n,z,w;cin>>n>>z>>w;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  int score=max(a[0]-w,w-a[0]);
  if(n>=2){
    int x=max(w-a[n-1],a[n-1]-w);
    int y=max(a[n-2]-a[n-1],a[n-1]-a[n-2]);
    score=max(x,y);
  }
  cout<<score<<endl;
  return 0;
}