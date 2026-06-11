#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<pair<int,int>>vec;
  int flag=0;
  if(N%2 == 0){
    flag=1;
  }
  
  if(flag){
    for(int i=1;i<=N/2;i++){
      vec.emplace_back(i,N-i+1);
    }
  }
  if(flag != 1){
    for(int i=1;i<=(N-1)/2;i++){
      vec.emplace_back(i,N-i);
    } 
    vec.emplace_back(N,0);
  }
  
  
  if(flag){
    cout<<N*(N/2-1)<<endl;
  }
  if(flag != 1){
    cout<<(N-1)*(N-1)/2<<endl;
  }
  if(flag){
    for(int i=0;i<N/2;i++){
      for(int j=i+1;j<N/2;j++){
        cout<<vec[i].first<<" "<<vec[j].first<<endl;
        cout<<vec[i].first<<" "<<vec[j].second<<endl;
        cout<<vec[i].second<<" "<<vec[j].first<<endl;
        cout<<vec[i].second<<" "<<vec[j].second<<endl;
      }
    }
  }
  
  if(flag != 1){
    for(int i=0;i<N/2+1;i++){
      for(int j=i+1;j<N/2+1;j++){

        cout<<vec[i].first<<" "<<vec[j].first<<endl;
        cout<<vec[i].second<<" "<<vec[j].first<<endl;
        if(vec[j].second != 0){
          cout<<vec[i].first<<" "<<vec[j].second<<endl;
          cout<<vec[i].second<<" "<<vec[j].second<<endl;
        }
      }
    }
  }  

  return 0;
}
