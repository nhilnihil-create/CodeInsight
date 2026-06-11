#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  string S;cin>>S;
  priority_queue<int> A;
  for(int j=1;j<N;j++){
    vector<bool> X(26,false);
    int ans=0;
    for(int i=0;i<j;i++) X.at(S.at(i)-'a')=true;
    for(int i=j;i<N;i++){
      if(X.at(S.at(i)-'a')){
        X.at(S.at(i)-'a')=false;
        ans++;
      }
    }
    A.push(ans);
  }
  cout<<A.top()<<endl;
  
}

