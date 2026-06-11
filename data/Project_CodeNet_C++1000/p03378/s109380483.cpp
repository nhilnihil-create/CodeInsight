#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M,X;
  cin>>N>>M>>X;
  vector<int> a(M);
  for(int i=0;i<M;i++){
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());
  int count=0;
  for(int x:a){
    if(x<X){
      count++;
    
    }
  }
  cout<<min(count,M-count)<<endl;
}