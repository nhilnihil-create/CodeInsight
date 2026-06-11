#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int k=0,l=1000000000;
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    k=max(k,j);
    l=min(l,j);
  }
  cout<<k-l<<endl;
}