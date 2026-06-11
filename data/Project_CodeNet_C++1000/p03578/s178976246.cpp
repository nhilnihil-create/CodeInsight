#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  map<int,int> D,T;
  cin>>N;
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    D[j]++;
  }
  cin>>M;
  for(int i=0;i<M;i++){
    int j;
    cin>>j;
    T[j]++;
  }
  for(pair<int,int> i:T)
    if(i.second>D[i.first]){
      cout<<"NO"<<endl;
      return 0;
    }
  cout<<"YES"<<endl;
}