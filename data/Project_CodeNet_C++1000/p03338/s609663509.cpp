#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  string S;
  cin>>N>>S;
  vector<pair<int,int>> A(26,make_pair(N,N));
  for(int i=0;i<N;i++){
    if(A[S[i]-'a'].first==N)
      A[S[i]-'a'].first=i;
    A[S[i]-'a'].second=i;
  }
  vector<int> B(N+1,0);
  for(int i=0;i<26;i++){
    B[A[i].first]++;
    B[A[i].second]--;
  }
  int ma=B[0];
  for(int i=0;i<N-1;i++){
    B[i+1]+=B[i];
    ma=max(ma,B[i+1]);
  }
  cout<<ma<<endl;
}