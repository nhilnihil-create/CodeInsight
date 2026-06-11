#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int>pl(n);
  for(int i=0;i<n;i++){
    int t;cin>>t;t--;
    pl[t]=i;
  }
  int l=0,cnt=0,p=-1;
  for(int i=0;i<n;i++){
    if(p<pl[i]){
      cnt ++;
    }
    else{
      l=max(l,cnt);
      cnt=1;
    }
    p=pl[i];
  }
  l=max(l,cnt);
  cout<<n-l<<endl;
}