#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>L(N);
  int allsum=0;
  for(int i=0;i<=N-1;i++){
  
    cin>>L[i];
    allsum+=L[i];
  }
  sort(L.begin(),L.end());
  if(allsum-L[N-1]>L[N-1])cout<<"Yes";
  else cout<<"No";
  return 0;
}