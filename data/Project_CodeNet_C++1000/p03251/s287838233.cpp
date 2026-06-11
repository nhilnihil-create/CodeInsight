#include <bits/stdc++.h>
using namespace std;

int main(){

  int n,m,x,y;
  cin>>n>>m>>x>>y;
  
  vector<int> datax(n);
  vector<int> datay(m);
  
  for (int i=0;i<n;i++){
    cin>>datax.at(i);
  }
  
  for (int i=0;i<m;i++){
    cin>>datay.at(i);
  }
  
  datax.push_back(x);
  datay.push_back(y);
  
  sort(datax.begin(),datax.end());
  sort(datay.begin(),datay.end());
  
  if (datax.at(n)<datay.at(0)){
    cout<<"No War"<<endl;
  }
  
  else {
    cout<<"War"<<endl;
  }
  
  

}
  











