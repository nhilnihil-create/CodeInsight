#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  map<int,int> A;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A[a]++;
  }
  int j=0;
  for(pair<int,int> p:A)
    if(p.second>=p.first)
      j+=p.second-p.first;
    else
      j+=p.second;
  cout<<j<<endl;
}