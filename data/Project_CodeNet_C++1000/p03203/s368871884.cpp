#include <bits/stdc++.h>
using namespace std;

signed main(){
  int H,W,N;
  cin>>H>>W>>N;
  std::vector<int> X(N),Y(N);
  for(int i=0;i<N;i++)cin>>X[i]>>Y[i];
  int ans=H;
  typedef pair<int,int> P;
  std::vector<P> v(N);
  for(int i=0;i<N;i++)v[i]=P(X[i],Y[i]);
  sort(v.begin(),v.end());
  map<int,int> m;
  m[1]=1;
  m[0]=-1e7;
  int x,y;
  for(int i=0;i<N;i++){
    x=v[i].first;y=v[i].second;
    //cout<<y-x<<" "<<(--m.upper_bound(x))->second-1<<endl;
    if(y-x>(--m.lower_bound(x))->second-1)continue;
    if(y-x==(--m.lower_bound(x))->second-1)m[x]=y-x;
    else{ans=x-1;break;}
  }
  cout<<ans<<endl;
}
