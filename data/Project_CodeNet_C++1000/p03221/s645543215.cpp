#include<bits/stdc++.h>
using namespace std;

int main(void){
  int n,m;cin>>n>>m;
  vector<int> p(m),y(m);
  vector<vector<int>> py(n,vector<int>(0));
  for(int i=0; i<m; ++i){ cin>>p[i]>>y[i]; py[p[i]-1].push_back(y[i]);}
  for(int i=0; i<n; ++i) sort(py[i].begin(), py[i].end());
  for(int i=0; i<m; ++i) y[i]=1+lower_bound(py[p[i]-1].begin(),py[p[i]-1].end(),y[i])-py[p[i]-1].begin();
  for(int i=0; i<m; ++i){
    int cnt=100000/(1+p[i])*10;
    while(cnt/=10) cout<<0;
    cout<<p[i];
    cnt=100000/(1+y[i])*10;
    while(cnt/=10) cout<<0;
    cout<<y[i]<<endl;
  }
  return 0;
}
