#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod=1e9+7;

signed main(){
  int n;
  cin>>n;
  if(n==1){
    cout<<"Yes"<<endl;
    cout<<2<<endl;
    cout<<1<<" "<<1<<endl;
    cout<<1<<" "<<1<<endl;
    return 0;
  }
  bool f=false;
  int i;
  for(i=1;i*(i+1)<=n*2;i++){
    if(i*(i+1)==n*2){
      f=true;
      break;
    }
  }
  if(!f){
    cout<<"No"<<endl;
    return 0;
  }

  cout<<"Yes"<<endl;
  cout<<i+1<<endl;

  vector<vector<int> > ans(i+1,vector<int>(i));

  int np=1;
  for(int j=0;j<i;j++){
    for(int k=0;k<i-j;k++)ans[j][j+k]=np+k;
    for(int k=0;k<i-j;k++)ans[j+k+1][j]=np+k;
    np+=i-j;
  }

  for(int j=0;j<i+1;j++){
    cout<<i<<" ";
    for(int k=0;k<i;k++){
      cout<<ans[j][k];
      if(k!=i-1)cout<<" ";
    }
    cout<<endl;
  }

}
