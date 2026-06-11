#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,M;
  cin>>N>>M;
  vector<int> vec(N+2);
  
  for(int i=0;i<M;i++){
    int L,R;
    cin>>L>>R;
    vec.at(L)++;
    vec.at(R+1)--;
  }
  vector<int> rui(N+2);
  for(int i=1;i<=N+1;i++){
    rui.at(i)=rui.at(i-1)+vec.at(i);
  }
  int sum=0;
  for(int i=1;i<=N;i++){
    if(rui.at(i)==M) sum++;
  }
  cout<<sum<<endl;
    
  
  
}