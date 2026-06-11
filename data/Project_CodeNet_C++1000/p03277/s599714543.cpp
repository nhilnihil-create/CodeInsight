#include "bits/stdc++.h"
using namespace std;

long long int mod=1e9+7;
long long int n;
vector<long long int> a(101010);
vector<long long int> bit(202020);

int sum(long long int i){
  long long int s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(long long int i,long long int x){
  while(i<=202020){
    bit[i]+=x;
    i+=i&-i;
  }
}

bool ch(long long int x){
  for(long long int i=0;i<202020;i++)bit[i]=0;
  vector<long long int> b(n);
  for(long long int i=0;i<n;i++){
    if(a[i]>=x){
      b[i]=1;
    }else{
      b[i]=-1;
    }
  }
  vector<long long int> rui(n+1);
  rui[0]=n+1;
  for(long long int i=1;i<n+1;i++)rui[i]=rui[i-1]+b[i-1];
  long long int tmp=0;
  //for(int i=0;i<n+1;i++)cout<<rui[i]<<" ";
  //cout<<endl;
  for(long long int i=0;i<n+1;i++){
    tmp+=i-sum(rui[i]);
    add(rui[i],1);
  }
  long long int y=(n*(n+1)/2)/2;
  //cout<<y<<" "<<tmp<<endl;
  if(tmp>y){
    return true;
  }else{
    return false;
  }
}

int main(){
  cin>>n;
  for(long long int i=0;i<n;i++){
    cin>>a[i];
    bit[i]=0;
  }

  long long int l,r,mid;
  l=0;
  r=1e9+1;
  while(r-l>1){
    mid=(l+r)/2;
    //cout<<mid<<endl;
    if(ch(mid)){
      r=mid;
    }else{
      l=mid;
    }
  }
  cout<<l<<endl;
}
