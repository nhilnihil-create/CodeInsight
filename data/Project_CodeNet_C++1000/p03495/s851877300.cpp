#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  map<int,int> A;
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    A[j]++;
  }
  vector<int> B(0);
  for(pair<int,int> p:A)
    B.push_back(p.second);
  sort(B.begin(),B.end());
  int j=0;
  for(int i=0;i<(int)B.size()-K;i++){
    j+=B[i];
  }
  cout<<j<<endl;
}