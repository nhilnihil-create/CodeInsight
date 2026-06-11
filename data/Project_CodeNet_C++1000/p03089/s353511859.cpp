#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  int vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  int ans[n];
  int size=n;
  int now=0;
  while(size>=1){
    int flag=0;
    for(int i=size-1;i>=0;i--){
      if(vec[i]==i+1){
        ans[now]=vec[i];
        now++;
        flag++;
        for(int j=0;j<size;j++){
          if(j<i){
            vec[j]=vec[j];
          }
          if(j>i){
            vec[j-1]=vec[j];
          }
        }
        size--;
        break;
      }
    }
    if(flag==0){
      cout<<-1<<endl;
      return 0;
    }
  }
  for(int i=n-1;i>=0;i--){
    cout<<ans[i]<<endl;
  }
}