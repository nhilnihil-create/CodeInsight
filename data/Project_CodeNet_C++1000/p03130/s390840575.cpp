#include<bits/stdc++.h>
using namespace std;

int main(){
  int cnt[4]={0,0,0,0};
  for(int i=0;i<3;i++){
    int a,b; cin>>a >>b;
    a--; b--;
    cnt[a]++; cnt[b]++;
  }
  
  for(int i=0;i<4;i++){
    if(cnt[i]>2){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  
  cout<<"YES"<<endl;
  return 0;
}