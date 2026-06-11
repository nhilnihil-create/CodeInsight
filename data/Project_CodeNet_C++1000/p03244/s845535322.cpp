#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int vec[n];
  map<int,int> ma;
  map<int,int> mab;
  for(int i=0;i<n;i++){
    cin>>vec[i];
    if(i%2==0){
      ma[vec[i]]++;
    }
    else{
      mab[vec[i]]++;
    }
  }
  int a=0,b=0,c=1e6,d,e=0,f=0,g=1e6,h;
  for(int i=0;i<n;i+=2){
    if(ma[vec[i]]>=a){
      b=a;
      d=c;
      a=ma[vec[i]];
      c=vec[i];
      ma[vec[i]]=0;
    }
    else if(ma[vec[i]]>=b){
      b=ma[vec[i]];
      d=vec[i];
      ma[vec[i]]=0;
    }
  }
  for(int i=1;i<n;i+=2){
    if(mab[vec[i]]>=e){
      f=e;
      h=g;
      e=mab[vec[i]];
      g=vec[i];
      mab[vec[i]]=0;
    }
    else if(mab[vec[i]]>=f){
      f=mab[vec[i]];
      h=vec[i];
      mab[vec[i]]=0;
    }
  }
  if(c!=g){
    cout<<n-a-e<<endl;
    return 0;
  }
  cout<<min(n-a-f,n-b-e)<<endl;
  return 0;
}