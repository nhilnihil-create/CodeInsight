#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> l(m);
  vector<int> r(m);
  rep(i,m){
    cin>>l[i];
    cin>>r[i];
  }
  sort(all(l));
  reverse(all(l));
  sort(all(r));
  int ans=r[0]-l[0]+1;
  if(ans<0){
    ans=0;
  }
  cout<<ans<<endl;
}