#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> path(4);
  for(int i=0;i<3;i++){
    int a,b; cin>>a>>b;
    a--; b--;
    path[a]++;
    path[b]++;
  }sort(path.begin(),path.end());
  if(path[0]==1 && path[1]==1 && path[2]==2){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}