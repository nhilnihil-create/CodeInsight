///スマホコーディング
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
const int inf=1e9;
int main(){
  int a,b,c,d;cin>>a>>b>>c>>d;
  int ans=min(a,b);
  ans+=min(c,d);
  cout<<ans<<endl;
  return 0;
}