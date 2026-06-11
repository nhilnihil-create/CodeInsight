#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  map<char,int> A;
  for(int i=0;i<N;i++){
    char c;
    cin>>c;
    A[c]++;
  }
  int64_t k=1;
  for(pair<char,int> i:A){
    k*=(i.second+1);
    k=(k-1)%1000000007+1;
  }
  cout<<k-1<<endl;
}