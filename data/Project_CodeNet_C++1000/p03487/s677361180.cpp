#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,i,y=0;
  map<int,int> m;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>a;
    if(m.count(a)) m.at(a)++;
    else m[a]=1;
  }
  for(auto z:m){
    if(z.first<z.second) y+=z.second-z.first;
    else if(z.first>z.second) y+=z.second;
  }
  cout<<y<<endl;
}