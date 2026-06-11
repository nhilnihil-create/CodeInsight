#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int n,x,k,l,r,i;
  cin>>s;
  n=s.length();
  vector<int> v;
  x=1;
  for(i=1;i<n;i++){
    if(s.at(i)==s.at(i-1)) x++;
    else{
      v.push_back(x);
      x=1;
    }
  }
  v.push_back(x);
  k=n;
  l=0;
  r=v.size()-1;
  while(l<r){
    if(v.at(l)<=v.at(r)){
      k=min(k,n-v.at(l));
      v.at(l+1)+=v.at(l);
      v.at(l)=0;
      l++;
    }
    else if(v.at(l)>v.at(r)){
      k=min(k,n-v.at(r));
      v.at(r-1)+=v.at(r);
      v.at(r)=0;
      r--;
    }
  }
  cout<<k<<endl;
}