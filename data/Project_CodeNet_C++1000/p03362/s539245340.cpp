#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
bool fact(int m){
  if(m%2==0)return false; 
  int s=sqrt(m);
  for(int j=3;j<=s;j+=2){
    if(m%j==0) return false;
  }
  return true ;
} 
int main(){
  int n,cnt=0;
  cin>>n;
  vector<int> v;
  for(int i=11;cnt<n;i+=10){
     if(fact(i)){
        v.push_back(i);
        cnt++; 
     }
  }
    rep(i,n)
      printf("%d ",v[i]);
  return 0;
}