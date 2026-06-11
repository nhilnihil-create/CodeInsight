#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N;
  cin>>N;
  vector<int64_t> A(N);
  for(int64_t i=0;i<N;i++){
    int64_t j;
    cin>>j;
    A.at(i)=j-(i+1);
  }
  sort(A.begin(),A.end());
  int64_t l=A.at(N/2),k=0;
  for(int64_t &i:A)
    k+=max(i-l,l-i);
  cout<<k<<endl;
}