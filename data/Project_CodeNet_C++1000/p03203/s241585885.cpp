#include<bits/stdc++.h>
using namespace std;

int main (){
  int h,w,n;
  cin>>h>>w>>n;
  swap(h,w);
  vector<pair<int,int>> vs(n);
  for(int i=0;i<n;i++){
    cin>>vs[i].second>>vs[i].first;
    vs[i].first--,vs[i].second--;
  }

  set<pair<int,int>> s;
  for(int i=0;i<n;i++) s.insert(vs[i]);
  for(int i=0;i<n;i++) s.insert({i,w});
  vector<int> okw(h,w);
  okw[0]=0;
  for(int i=1;i<h;i++){
    for(int j=okw[i-1]+1;j<=w;j++){
      if(!s.count({i,j})){
	okw[i]=j;
	break;
      }
    }
  }

  vector<int> obj(h,w);

  for(int i=0;i<n;i++){
    if(okw[vs[i].first]<=vs[i].second){
      obj[vs[i].first]=min(obj[vs[i].first],vs[i].second);
    }
  }

  int res=1e8;
  for(int i=0;i<h;i++){
    int sc=obj[i];
    res=min(res,sc);
  }
  cout<<res<<endl;
  
  
  return 0;
}