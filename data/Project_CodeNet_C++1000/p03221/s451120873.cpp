#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  vector<pair<int,int>> p;
  vector<int> q(N,1);
  map<pair<int,int>,int> m;
  vector<int> x(M);
  vector<int> y(M);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    p.push_back(make_pair(b,a));
    m[make_pair(b,a)]=i;
    x.at(i)=a;
  }
  sort(p.begin(),p.end());
  for(int i=0;i<M;i++){
    y.at(m[p.at(i)])=q.at(p.at(i).second-1);
    q.at(p.at(i).second-1)++;
  }
  for(int i=0;i<M;i++){
    if(x.at(i)<10){
      cout<<"00000"<<x.at(i);
    }
    else if(x.at(i)<100){
      cout<<"0000"<<x.at(i);
    }
    else if(x.at(i)<1000){
      cout<<"000"<<x.at(i);
    }
    else if(x.at(i)<10000){
      cout<<"00"<<x.at(i);
    }
    else if(x.at(i)<100000){
      cout<<"0"<<x.at(i);
    }
    else{
      cout<<x.at(i);
    }
    
    if(y.at(i)<10){
      cout<<"00000"<<y.at(i);
    }
    else if(y.at(i)<100){
      cout<<"0000"<<y.at(i);
    }
    else if(y.at(i)<1000){
      cout<<"000"<<y.at(i);
    }
    else if(y.at(i)<10000){
      cout<<"00"<<y.at(i);
    }
    else if(y.at(i)<100000){
      cout<<"0"<<y.at(i);
    }
    else{
      cout<<y.at(i);
    }
    cout<<endl;
  }
}