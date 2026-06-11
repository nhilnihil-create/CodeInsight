#include <bits/stdc++.h>
using namespace std;






int main(){

  
  int n,k;
  cin>>n>>k;
  
  vector<int> height(n);
  
  for (int i=0;i<n;i++){
    int tmp;
    cin>>tmp;
    height.at(i)=tmp;
  }
  
  sort(height.begin(),height.end());
  
  int dis=-1;
  
  for (int i=0;i<=n-k;i++){
    int tmp;
    tmp=height.at(i+k-1)-height.at(i);
    
    if (dis==-1){
      dis=tmp;
    }
    else {
      dis=min(dis,tmp);
    }
  }
  
  cout<<dis<<endl;
  

        
}