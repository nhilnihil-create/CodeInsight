#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> v;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    v.push_back({a,0,i});
    v.push_back({b-1,1,i});
  }
  sort(v.begin(),v.end());
  int c=0;
  vector<bool> q(m,0);
  vector<int> k;
  for(int i=1,p=0;i<n&&p<v.size();i++){
    while(p<v.size()&&v.at(p).at(0)<=i){
      if(v.at(p).at(1)==0)
        k.push_back(v.at(p).at(2));
      else{
        if(q.at(v.at(p).at(2))==0){
          c++;
          while(!k.empty()){
            q.at(k.back())=1;
            k.pop_back();
          }
        }
      }
      p++;
    }
  }
  cout<<c<<endl;
}