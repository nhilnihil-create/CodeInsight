#include<bits/stdc++.h>
using namespace std;


int main(){
  int n,x;
  cin >> n >> x;
  int mi=10000;
  int su=0;
  for(int i=0;i<n;++i){
    int m;
    cin >> m;
    su+=m;
    mi=min(mi,m);
  }
  int ans=n;
  x-=su;
  ans+=x/mi;
  cout << ans << endl;
  return 0;
}
