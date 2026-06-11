#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  if(n==3){
    cout<<2<<" "<<5<<" "<<63<<endl;
    return 0;
  }
  if(n==6){
    cout<<2<<" "<<4<<" "<<6<<" "<<12<<" "<<3<<" "<<9<<endl;
    return 0;
  }
  vector<int> v,w;
  int u;
  for(int i=8;;i+=8){
    if(i>=n){
      u=i;
      break;
    }
  }
  for(int i=2;i<=(3*u)/2;i+=2)v.push_back(i);
  for(int i=3;i<=(u/4)*6-3;i+=6)w.push_back(i);
  if(n%8==1)v.erase(v.end()-7,v.end());
  if(n%8==2)v.erase(v.end()-6,v.end());
  if(n%8==3){
    v.erase(v.end()-3,v.end());
    w.erase(w.end()-2,w.end());
  }
  if(n%8==4)v.erase(v.end()-4,v.end());
  if(n%8==5)v.erase(v.end()-3,v.end());
  if(n%8==6)w.erase(w.end()-2,w.end());
  if(n%8==7)v.erase(v.end()-1,v.end());
  for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
  for(int i=0;i<w.size();i++)cout<<w[i]<<" ";
  cout<<endl;
}