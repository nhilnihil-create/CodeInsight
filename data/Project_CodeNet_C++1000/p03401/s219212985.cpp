#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;

int abs(int x){
  if(x<0){
    x=-x;
  }
  return x;
}

int main(){
  int N;
  cin>>N;
  vector<int> A(N+2,0);
  for(int i=1;i<=N;i++){
    cin>>A.at(i);
  }
  vector<int> cost(N+1),skip(N+1);
  int sum=0;
  for(int i=0;i<=N;i++){
    cost.at(i)=abs(A.at(i+1)-A.at(i));
    sum+=cost.at(i);
  }
  for(int i=1;i<=N;i++){
    skip.at(i)=abs(A.at(i+1)-A.at(i-1));
  }
  for(int i=1;i<=N;i++){
    cout<<sum-cost.at(i-1)-cost.at(i)+skip.at(i)<<endl;
  }
}
