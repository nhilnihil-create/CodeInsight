#include <bits/stdc++.h>
using namespace std;

int main(){
  
int n,t;
  cin>>n>>t;
  
  vector<int> cost(n);
  vector<int> time(n);
  
  for (int i=0;i<n;i++){
    cin>>cost.at(i)>>time.at(i);
  }
  
  vector<int> tmp;
  
  for (int i=0;i<n;i++){
    if (time.at(i)<=t){
      tmp.push_back(i);
    }
  }
  
  if (int(tmp.size())==0){
    cout<<"TLE"<<endl;
  }
  
  else {
    int answer=cost.at(tmp.at(0));
    
    for (int x:tmp){
      if (cost.at(x)<answer){
        answer=cost.at(x);
      }
    }
    cout<<answer<<endl;
  }
  
  
}
  











