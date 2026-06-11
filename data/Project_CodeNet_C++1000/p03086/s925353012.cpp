#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;cin>>S;
  priority_queue<int> ans;
  int count=0;
  int N=S.size();
  for(int i=0;i<N;i++){
    if(S.at(i)=='A' || S.at(i)=='G' || S.at(i)=='C' || S.at(i)=='T') count++;
    else{
      ans.push(count);
      count=0;
    }
  }
  ans.push(count);
  cout<<ans.top()<<endl;
}
