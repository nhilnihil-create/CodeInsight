#include <bits/stdc++.h>
using namespace std;

void a(int &j,vector<int> &h,int l,int r){
  if(l>=r)
    return;
  int i=100;
  vector<int> p;
  for(int k=l;k<r;k++)
    i=min(i,h.at(k));
  j+=i;
  for(int k=l;k<r;k++){
    if(i==h.at(k))
      p.push_back(k);
    h.at(k)-=i;
  }
  int k=l,o=p.at(0);
  p.push_back(r);
  a(j,h,k,o);
  for(int u=0;u<p.size()-1;u++){
    k=p.at(u)+1;
    o=p.at(u+1);
    a(j,h,k,o);
  }
}

int main(){
  int N;
  cin>>N;
  vector<int> h(N);
  for(int &i:h)
    cin>>i;
  int j=0;
  a(j,h,0,N);
  cout<<j<<endl;
}