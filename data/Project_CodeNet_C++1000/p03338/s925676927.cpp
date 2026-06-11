#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;string S;cin>>N>>S;
  priority_queue<int> ans;
  for(int i=1;i<N;i++){
    string A=S.substr(0,i);
    string B=S.substr(i,N-i);
    vector<bool> X(26,false);
    int count=0;
    for(int j=0;j<N-i;j++) X.at(B.at(j)-'a')=true;
    for(int j=0;j<i;j++){
      if(X.at(A.at(j)-'a')){
        X.at(A.at(j)-'a')=false;
        count++;
      }
    }
    ans.push(count);
  }
  cout<<ans.top()<<endl;
}

