#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M, c;
  cin>>N>>M>>c;
  vector <int> vec1(M);
  for(int i=0; i<M; i++){
    cin>>vec1.at(i);
  }
  vector <vector<int>> vec2(N,vector <int>(M,0));
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin>>vec2.at(i).at(j);
    }
  }
  int ans=0;
  int sum=0;
  for(int i=0; i<N; i++){
    sum=0;
    for(int j=0; j<M; j++){
      sum+=vec1.at(j)*vec2.at(i).at(j);    
    }
    if(sum+c>0){
      ans++;
    }
  }
  cout<<ans<<endl;
}
      
