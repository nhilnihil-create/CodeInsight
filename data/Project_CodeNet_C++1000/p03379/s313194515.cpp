#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<pair<int,int>> X(N);
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    X[i]=make_pair(j,i);
  }
  sort(X.begin(),X.end());
  map<int,int> A;
  for(int i=0;i<N;i++){
    if(i<N/2)
      A[X[i].second]=X[N/2].first;
    else
      A[X[i].second]=X[N/2-1].first;
  }
  for(int i=0;i<N;i++)
    cout<<A[i]<<endl;
}