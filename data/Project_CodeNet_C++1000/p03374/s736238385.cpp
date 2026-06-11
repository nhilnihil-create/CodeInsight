#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int N,C;
  cin>>N>>C;
  std::vector<int> x(N),v(N);
  for(int i=0;i<N;i++)cin>>x[i]>>v[i];
  std::vector<int> tm(N);
  tm[0]=v[0]-x[0];
  for(int i=1;i<N;i++)tm[i]=tm[i-1]+v[i]-(x[i]-x[i-1]);
  std::vector<int> gm(N);
  gm[0]=v[N-1]-(C-x[N-1]);
  for(int i=1;i<N;i++)gm[i]=gm[i-1]+v[N-1-i]-(x[N-1-i+1]-x[N-1-i]);
  int ans=0;
  for(int i=0;i<N;i++){ans=max(ans,tm[i]);}
  for(int i=0;i<N;i++){ans=max(ans,gm[i]);}
  //cout<<111<<" "<<ans<<endl;
  std::vector<int> ge(N);
  int k=0;
  for(int i=0;i<N;i++){
    if(gm[i]>k){
      ge[i]++;
      k=gm[i];
    }
  }
  int l=N-1;
  for(int i=0;i<N;i++){
    while((ge[l]==0||l+i>=N-1)&&l>=0)l--;
    if(l<0)break;
    ans=max(ans,gm[l]+tm[i]-x[i]);
    //cout<<222<<" "<<ans<<endl;
  }

  std::vector<int> te(N);
  k=0;
  for(int i=0;i<N;i++){
    if(tm[i]>k){
      te[i]++;
      k=tm[i];
    }
  }
  l=N-1;
  for(int i=0;i<N;i++){
    while((te[l]==0||l+i>=N-1)&&l>=0)l--;
    if(l<0)break;
    ans=max(ans,tm[l]+gm[i]-(C-x[N-i-1]));
    //cout<<333<<" "<<ans<<endl;
  }
  cout<<ans<<endl;
  //for(int i=0;i<N;i++)cout<<te[i]<<" "<<ge[i]<<endl;
}
