#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int x,y;
  cin>>x>>y;
  if(x%y==0) cout<<-1<<'\n';
  else{
    int sum=0;
    while(true){
      sum+=x;
      if(sum%y!=0) break;
    }
    cout<<sum<<'\n';
  }
  return 0;
}
