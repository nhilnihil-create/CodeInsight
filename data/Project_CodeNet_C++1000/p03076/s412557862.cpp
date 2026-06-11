#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  int n=5;
  vector<int>time={a,b,c,d,e};
  vector<int>nexttime(n);
  for(int i=0;i<n;i++){
    if(time[i]%10==0)  nexttime[i]=time[i];
    else  nexttime[i]=10-time[i]%10+time[i];
  }
  int bst=1e9;
  for(int i=0;i<n;i++){
    int sum=0;
    for(int j=0;j<n;j++){
      if(i==j){
        sum+=time[j];
      }
      else{
        sum+=nexttime[j];
      }
    }
    bst=min(bst,sum);
  }
  cout<<bst<<endl;
}
      
  
  