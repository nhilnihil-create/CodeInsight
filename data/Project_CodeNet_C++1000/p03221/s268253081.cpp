#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,p,y,x,i,j,l;
  string s,t;
  cin>>n>>m;
  vector<tuple<int,int,int>> py(m);
  vector<pair<int,string>> id(m);
  for(i=0;i<m;i++){
    cin>>p>>y;
    py.at(i)=make_tuple(p,y,i);
  }
  sort(py.begin(),py.end());
  for(i=0;i<m;i++){
    if(i==0||(i>0&&get<0>(py.at(i-1))!=get<0>(py.at(i)))){
      s=to_string(get<0>(py.at(i)));
      l=s.length();
      for(j=1;j<=6-l;j++) s='0'+s;
      x=1;
    }
    else x++;
    t=to_string(x);
    l=t.length();
    for(j=1;j<=6-l;j++) t='0'+t;
    id.at(i)=make_pair(get<2>(py.at(i)),s+t);
  }
  sort(id.begin(),id.end());
  for(auto z:id) cout<<z.second<<endl;
}