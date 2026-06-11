#include <bits/stdc++.h>
using namespace std;


int main (){
  int N,M,C;
  cin>>N>>M>>C;
  vector<int>B(M);
  int count;
  int f;
  
  for(int i=0;i<M;i++){
    cin>>B.at(i);
  }
  for(int j=1;j<N+1;j++){
    vector<int>A(M);
    int sum=0;
    for(int k=0;k<M;k++){
      cin>>A.at(k);
      f=A.at(k)*B.at(k);
      sum+=f;
    }
    
    if(sum+C>0){
     count++;
    }
  }
 cout<<count<<endl;
}