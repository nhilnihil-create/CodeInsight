#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int list[110];
  cin>>n;
  for(int i=0;i<n;i++)cin>>list[i];
  
  int num[110] = {0};
  for(int i=0;i<n;i++){
    num[list[i]]++;
  }
  
  int ans=0;
  for(int i=1;i<110;i++){
    if(num[i]){
      ans++;
    }
  }
  cout<<ans<<endl;
}
