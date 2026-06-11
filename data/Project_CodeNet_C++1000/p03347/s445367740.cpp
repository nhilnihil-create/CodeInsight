#include<bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin>>n;
  long long a[n];
  bool flg=1;
  for(int i=0;i<n;i++){
  	cin>>a[i];
    if(i==0){if(a[i]!=0) flg=0;}
    if(i){if(a[i]-a[i-1]>1) flg=0;}
  }
  long long ans=0,count=0;
  if(flg){
    for(int i=1;i<n;i++){
      
      if(a[i]>a[i-1]){
        count++;
        ans++;
      }
      else if(a[i]==a[i-1]){
      	ans+=count;
      }
      else{
        count=a[i];
        ans+=count;
      } 
    }
    cout<<ans<<endl;
  }
  else cout<<-1<<endl;
}