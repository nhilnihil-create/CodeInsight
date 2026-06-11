#include<bits/stdc++.h>
using namespace std;
int main(){
  int l;
  cin>>l;
  int x=l;
  int d=0;
  vector<int> b;
  while(x>1){
    b.push_back(x%2);
    d++;
    x/=2;
  }
  vector<vector<int>> e;
  int p=1;
  for(int i=0;i<d;i++){
    e.push_back({i+1,i+2,0});
    e.push_back({i+1,i+2,p});
    p*=2;
  }
  int w=p;
  for(int i=d-1;i>=0;i--){
    p/=2;
    if(b.at(i)){
      e.push_back({i+1,d+1,w});
      w+=p;
    }
  }
  cout<<d+1<<' '<<e.size()<<endl;
  for(int i=0;i<e.size();i++)
    cout<<e.at(i).at(0)<<' '<<e.at(i).at(1)<<' '<<e.at(i).at(2)<<endl;
}