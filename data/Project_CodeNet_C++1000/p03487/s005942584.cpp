#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<long long>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A.begin(),A.end());
  vector<pair<long long,long long>>B;
  long long mark=0;
  for(int i=0;i<N;i++){
    if(A[i]!=mark){
      mark=A[i];
      B.push_back(make_pair(A[i],1));
    }
    else{
      B.at(B.size()-1).second++;
    }
  }
  long long count=0;
  for(int i=0;i<B.size();i++){
    if(B[i].first<B[i].second){
      count=count+B[i].second-B[i].first;
    }
    else if(B[i].first>B[i].second){
      count=count+B[i].second;
    }
  }
  cout<<count<<endl;
}
    
