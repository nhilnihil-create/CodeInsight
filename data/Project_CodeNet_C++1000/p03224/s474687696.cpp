#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, node;

void check(){
  
  for(int i=1;i<100000;i++){
    
    if( i * ( i - 1 ) / 2 == N ) node = i;
    
  }
  
}

vector<int> ans[100000];

signed main(){
  
  cin>>N;
  
  check();
  
  if( node == 0 ){
    cout<<"No"<<endl;
    return 0;
  }
  
  cout<<"Yes"<<endl;
  
  cout<<node<<endl;
  
  int num = 1;
  
  for(int i=0;i<node;i++){
    
    for(int j=i+1;j<node;j++){
      
      ans[i].push_back( num );
      
      ans[j].push_back( num );
      
      num++;
      
    }
    
  }
  
  for(int i=0;i<node;i++){
    cout<<node-1;
    for(int j=0;j<(int)ans[i].size();j++){
      cout<<' '<<ans[i][j];
    }
    cout<<endl;
  }
    
  return 0;
}
