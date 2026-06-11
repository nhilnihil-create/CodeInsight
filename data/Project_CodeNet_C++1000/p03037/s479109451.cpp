#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

  int N;
  int M;
  cin>>N>>M;
  vector<int>start(M);
  vector<int>end(M);
  for(int i=0;i<=M-1;i++){
  
    cin>>start[i];
    cin>>end[i];
  }
  sort(start.begin(),start.end());
  sort(end.begin(),end.end());
  if(end[0]<start[M-1]){
  
    cout<<0;
    return 0;
  }
  cout<<end[0]-start[M-1]+1;
  return 0;
}