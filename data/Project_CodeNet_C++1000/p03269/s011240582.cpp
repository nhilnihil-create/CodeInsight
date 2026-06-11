#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
  int l;cin>>l;
  int u;
  for(int i=0;;i++){
    int y=pow(2,i);
    if(y>l){
      u=i;
      break;
    }
  }
  vector<pii> v[u+1];
  int cnt=0;
  for(int i=1;i<u;i++){
    int r=pow(2,u-1-i);
    v[i].push_back(make_pair(i+1,r));
    v[i].push_back(make_pair(i+1,0));
    cnt+=2;
  }
  int now=l;
  for(int i=0;i<u-1;i++){
    int y=pow(2,i);
    int e=l/y;
    if(e%2){
      v[1].push_back(make_pair(u-i,now-y));
      cnt++;
      now-=y;
    }
  }
  cout<<u<<" "<<cnt<<endl;
  for(int i=1;i<u;i++){
    for(int j=0;j<v[i].size();j++){
      cout<<i<<" "<<v[i][j].first<<" "<<v[i][j].second<<endl;
    }
  }
}
        
  