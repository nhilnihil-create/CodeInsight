#include<iostream>
using namespace std;
int main(){

  int time[5];
  int truetime[5];
  int sum=0;
  int max=999;
  int ans=999;
  for(int i=0;i<=4;i++){
    cin>>time[i];
    truetime[i]=time[i];
    if(time[i]%10!=0){
    
      time[i]/=10;
      time[i]++;
      time[i]*=10;
    }
    sum+=time[i];
  }
  for(int i=0;i<=4;i++){
  
    max=sum-time[i]+truetime[i];
    if(max<ans)ans=max;
  }
  cout<<ans;
  return 0;
}