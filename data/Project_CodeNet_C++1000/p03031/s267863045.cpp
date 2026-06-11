#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int k[m];
  vector<vector<int>> a(m);
  for(int i=0;i<m;i++){
    cin>>k[i];
    for(int j=0;j<k[i];j++){
      int l;
      cin>>l;
      a[i].push_back(l);
    }
  }
  int p[m],ans=0;
  for(int i=0;i<m;i++) cin>>p[i];

  for(int bit=0;bit<(1<<n);bit++){
    int light=0;
    for(int i=0;i<m;i++){
      int cnt=0;
      for(int j=0;j<k[i];j++){
        if(bit&(1<<a[i][j]-1)) cnt++;
      }
      if(p[i]==0&&cnt%2==0) light++;
      if(p[i]==1&&cnt%2==1) light++;
    }
    if(light==m) ans++;
  }
  cout<<ans<<endl;
  return 0;
}
