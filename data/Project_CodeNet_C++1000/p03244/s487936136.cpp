#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  unordered_map<int,int> a,b;
  for(int i=0;i<n;i++){
    int j;
    cin>>j;
    if(i%2==0){
      if(a.count(j))
        a[j]++;
      else
        a[j]=1;
    }
    else{
      if(b.count(j))
        b[j]++;
      else
        b[j]=1;
    }
  }
  pair<int,int> j,k,l,p;
  for(auto &i:a){
    if(j.second<i.second){
      k=j;
      j=i;
    }
    else if(k.second<i.second)
      k=i;
  }
  for(auto &i:b){
    if(l.second<i.second){
      p=l;
      l=i;
    }
    else if(p.second<i.second)
      p=i;
  }
  if(j.first!=l.first)
    cout<<n-j.second-l.second<<endl;
  else if(k.second+l.second<j.second+p.second)
    cout<<n-j.second-p.second<<endl;
  else
    cout<<n-k.second-l.second<<endl;
}