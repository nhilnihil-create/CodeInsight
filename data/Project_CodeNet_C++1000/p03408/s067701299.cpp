#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<string> s(N);
  for(int i=0;i<N;i++){
    cin>>s.at(i);
  }
  
  int M;
  cin>>M;
  vector<string> t(M);
  for(int i=0;i<M;i++){
    cin>>t.at(i);
  }
  
  int ans=0;
  
  vector<int> x(N);
  for(int i=0;i<N;i++){
    
    for(int j=0;j<N;j++){
      if(s.at(i)==s.at(j))x.at(i)++;
    }
    
    for(int j=0;j<M;j++){
      if(s.at(i)==t.at(j))x.at(i)--;
    }
    if(x.at(i)>ans)ans=x.at(i);
  }
  cout<<ans<<endl;
}