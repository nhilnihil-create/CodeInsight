#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,x,y,i;
  cin>>n>>m>>x;
  for(i=1;i<=m;i++){
    cin>>y;
    if(x<y) break;
  }
  cout<<min(i-1,m-i+1)<<endl;
}