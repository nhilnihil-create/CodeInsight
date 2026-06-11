#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N;
  vector<string> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  cin>>M;
  vector<string> B(M);
  for(int i=0;i<M;i++){
    cin>>B.at(i);
  }
  int sum =0;
  
  for(int i=0;i<N;i++){
    int sumz = 0;
    for(int j =0;j<N;j++){
      if(A.at(i)==A.at(j)){
        sumz++;
      }
    }
      for(int j =0;j<M;j++){
        if(A.at(i)==B.at(j)){
          sumz--;
        }
           }
           if(sumz>sum){
             sum=sumz;
           }
           }
           cout<<sum<<endl;
           }