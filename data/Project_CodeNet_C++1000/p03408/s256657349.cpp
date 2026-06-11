#include <bits/stdc++.h>
using namespace std;

 
int main() {
  int cou=0;
  int ans=0;
  int N;
  cin>>N;
  vector<string> test1(N);
  for(int i=0;i<N;i++){
    cin>>test1.at(i);}
  int M;
  cin>>M;
  vector<string> test2(M);
  for(int i=0;i<M;i++){
    cin>>test2.at(i);}
  
  for(int i=0;i<N;i++){
    cou=0;
    for(int j=0;j<N;j++){
      if(test1.at(i)==test1.at(j)){
        cou++;}
    }
    for(int j=0;j<M;j++){
       if(test1.at(i)==test2.at(j)){
        cou--;}
    }
    if(ans<=cou){
    ans=cou;
    }
  }
  cout<<ans<<endl;}