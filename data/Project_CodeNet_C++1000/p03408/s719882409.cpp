#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<string> S(N);
  for(int i=0;i<N;i++) cin>>S.at(i);
  int M;cin>>M;
  vector<string> T(M);
  for(int i=0;i<M;i++) cin>>T.at(i);
  priority_queue<int> A;
  sort(S.begin(),S.end());
  for(int i=0;i<N;i++){
    if(i>0 && S.at(i)==S.at(i-1)) continue; 
    string X=S.at(i);
    int count=0;
    for(int j=i;j<N;j++){
      if(X==S.at(j)) count++;
    }
    for(int j=0;j<M;j++){
      if(X==T.at(j)) count--;
    }
    A.push(count);
  }
  if(A.top()<0) cout<<0<<endl;
  else cout<<A.top()<<endl;
}
