#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin>>n;
  vector<pair<int,int>> p;
  vector<int> t(n+1);
  t[0]=0;
  p.push_back(make_pair(0,0));
  rep(i,n){
    int x, y;
    cin>>t[i+1];
    cin>>x>>y;
    p.push_back(make_pair(x,y));
  }
  bool ans=1;
  rep(i,n){
    int x0,y0,x1,y1;
    tie(x0,y0)=p[i];
    tie(x1,y1)=p[i+1];
    int dis=( (t[i+1]-t[i]) - (abs(x1-x0)+abs(y1-y0)) );
    if(!(dis>=0 && dis%2==0)){ans=0; break;}
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
