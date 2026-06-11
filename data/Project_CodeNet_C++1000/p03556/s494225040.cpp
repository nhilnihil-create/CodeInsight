#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,ans; cin>>N;
  int i=1;
  while(1){
    if(i*i>N) break;
    ans=i*i;
    i++;
  }
  cout<<ans<<endl;
}
