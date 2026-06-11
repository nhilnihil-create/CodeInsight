#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin>>N;
  
  vector<int> vec(N+1);
  for(int i=1;i<=N;i++){
    cin>>vec.at(i);
  }
  int sum=0;
  for(int i=0;i<100;i++){
    for(int j=1;j<=N;j++){
      if(vec.at(j)>=1){
        if(vec.at(j-1)==0){
          sum++;
        }
      }
    }
    for(int k=1;k<=N;k++){
      vec.at(k)=max(vec.at(k)-1,0);
    }
  }
  cout<<sum<<endl;
}