#include<bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
int main(void){
  int n,m;
  cin>>n>>m;
  vector<P> v(m);
  for(int i=0;i<m;i++){
    cin>>v[i].second>>v[i].first;
  }
  sort(v.begin(),v.end());
  int cnt=0;
  int num=-1;
  for(int i=0;i<m;i++){
    if(num<=v[i].second){
      cnt++;
      num=v[i].first;
    }
  }
  cout<<cnt<<endl;
  return 0;
}