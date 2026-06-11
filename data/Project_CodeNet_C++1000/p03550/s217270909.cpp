#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  int64_t Z,W;
  cin>>Z>>W;
  vector<int64_t>A(N+1);
  A.at(0)=W;
  for(int i=1;i<=N;i++){
  int64_t a; cin>>a;
    A.at(i)=a;
  }for(int i=0;i<=N;i++)
    A.at(i)=abs(A.at(i)-A.at(N));
  cout<<max(A.at(0),A.at(N-1))<<endl;;
  
    return 0;
}